/* 
 * File:   Bigram.h
 * Author: Aziz OKAY
 *
 * Created on December 16, 2016, 9:41 AM
 */

#ifndef BIGRAM_H
#define BIGRAM_H

#include <iostream>
#include <fstream>
#include <map>
using namespace std;
using std::map;


template <class T>
class Bigram;

template<class T>
ostream& operator<< ( ostream& out, const Bigram<T>& obj );

template<class T>
class Bigram {
    public:
        Bigram() {}
		Bigram(int type) {}
		
        virtual int numGrams() = 0;

        virtual pair<T, T> maxGrams() = 0;
        virtual int numOfGrams(T p1, T p2) = 0;
        virtual int readFile(const char *fileName) = 0;
        friend ostream& operator << <>(ostream& out, const Bigram<T>& base);
        
    private:
        virtual void fillMap(T elm1, T elm2) = 0;
        virtual void print(ostream& out) const = 0; 
};

#endif /* BIGRAM_H */

