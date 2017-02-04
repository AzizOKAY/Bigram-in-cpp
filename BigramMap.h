/*
 * File:   BigramMap.h
 * Author: Aziz OKAY
 *
 * Created on December 16, 2016, 9:42 AM
 */


#ifndef BIGRAMMAP_H
#define BIGRAMMAP_H

#include <iostream>
#include "Bigram.h"
#include <fstream>
#include <map>
using namespace std;
using std::map;

template <class T>
class BigramMap;

template<class T>
ostream& operator<< ( ostream& out, const BigramMap<T>& obj );


template<class T>
class BigramMap : public Bigram<T> {
	public:
		BigramMap(){}
		BigramMap(int dType) { dType = dType;}


		int numGrams();

		pair<T, T> maxGrams();
		int numOfGrams(T p1, T p2);
		int readFile(const char *fileName);
		friend ostream& operator << <>(ostream& out, const Bigram<T>& obj);
	private:
		int dType;
		map<pair<T, T>, int> bigram;
		void fillMap(T elm1, T elm2);
		void print(ostream& out) const;
};

#endif /* BIGRAMMAP_H */
