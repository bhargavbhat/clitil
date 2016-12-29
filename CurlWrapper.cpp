#include <cstring>
#include <algorithm>
#include "CurlWrapper.h"

static char error[256] = {};

typedef struct _tagMEMFILE
{
  char* data;
  size_t size;

  _tagMEMFILE()
  {
      data = NULL;
      size = 0;
  }
  ~_tagMEMFILE()
  {
      if (data)
          delete[] data;
      data = NULL;
      size = 0;
  }
} MEMFILE;

static MEMFILE* memfopen() 
{
  return new MEMFILE;
}

static void memfclose(MEMFILE* mf) 
{
  delete mf;
}

static size_t memfwrite(char* ptr, size_t size, size_t count, void* stream) 
{
    MEMFILE* mf = (MEMFILE*) stream;
    int block = size * count;
    if (!mf->data)
    {
        mf->data = new char[block];
    }
    else
    {
        size_t newsize = mf->size+block;
        size_t oldsize = mf->size;
        char* newdata = new char[newsize];
        std::copy_n(mf->data, std::min(oldsize, newsize), newdata);
        delete[](mf->data);
        mf->data=newdata;
    }
    
    if (mf->data) 
    {
        memcpy(mf->data + mf->size, ptr, block);
        mf->size += block;
    }
    return block;
}

std::string CurlWrapper::getJSON()
{
    std::string retVal;
    MEMFILE* mf = memfopen();
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, &error);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, memfwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, mf);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, ua.c_str());
    if (curl_easy_perform(curl) == CURLE_OK) 
    {
        retVal = std::string(mf->data, mf->data + mf->size);
    }
    curl_easy_cleanup(curl);
    memfclose(mf);
    return retVal;
}
