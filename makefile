all: exe


exe: _mainTester.o Bigram.o BigramMap.o BigramDyn.o singleBigram.o
	g++ _mainTester.o Bigram.o BigramMap.o BigramDyn.o singleBigram.o -o exe

_mainTester.o: _mainTester.cpp
	g++ -c _mainTester.cpp --std=c++11

Bigram.o: Bigram.cpp
	g++ -c Bigram.cpp --std=c++11

BigramMap.o: BigramMap.cpp
	g++ -c BigramMap.cpp --std=c++11


BigramDyn.o: BigramDyn.cpp
	g++ -c BigramDyn.cpp --std=c++11

singleBigram.o: singleBigram.cpp
	g++ -c singleBigram.cpp --std=c++11
		
clean:
	rm *.o exe
