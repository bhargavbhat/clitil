all: json11.a clitil

clitil: clitil.cpp curl_wrapper.cpp
	g++ -std=c++11 clitil.cpp curl_wrapper.cpp json11.a -lcurl -o clitil

json11.o: ./json11/json11.cpp
	g++ -std=c++11 -c ./json11/json11.cpp -I ./json11 -fno-rtti -fno-exceptions

json11.a: json11.o
	ar rvs json11.a json11.o

clean:
	@rm -f clitil *.a *.o

test:
	@./clitil
