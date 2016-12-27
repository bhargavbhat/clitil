CXX = g++ -std=c++11
CXXFLAGS =
AR = ar
ARFLAGS = rs

LIBFLAGS = -c -fno-rtti -fno-exceptions
LIBINC = -I ./json11

all: json11.a clitil

clitil: clitil.cpp curl_wrapper.cpp
	$(CXX) $(CXXFLAGS) clitil.cpp curl_wrapper.cpp json11.a -lcurl -o clitil

json11.o: ./json11/json11.cpp
	$(CXX) $(LIBFLAGS) ./json11/json11.cpp $(LIBINC) 

json11.a: json11.o
	$(AR) $(ARFLAGS) json11.a json11.o

clean:
	@rm -f clitil *.a *.o

test:
	@./clitil
