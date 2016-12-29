CXX = g++ -std=c++11
CXXFLAGS = -O3
AR = ar
ARFLAGS = rs
LIBFLAGS = -c -O3 -fno-rtti -fno-exceptions
LIBINC = -I ./json11
JSONLIB = json11.a
STRIP = strip -s
TARGET = clitil

all: json11.a clitil

clitil: clitil.cpp CurlWrapper.cpp CurlWrapper.h JsonParser.h JsonParser.cpp Config.h Config.cpp
	$(CXX) $(CXXFLAGS) clitil.cpp CurlWrapper.cpp JsonParser.cpp Config.cpp $(JSONLIB) -lcurl -o $(TARGET)
	$(STRIP) $(TARGET)

json11.a: ./json11/json11.cpp ./json11/json11.hpp
	$(CXX) $(LIBFLAGS) ./json11/json11.cpp $(LIBINC) 
	$(AR) $(ARFLAGS) $(JSONLIB) json11.o

clean:
	@rm -f clitil *.a *.o

test:
	@./clitil
