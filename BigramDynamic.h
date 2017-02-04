/*
 * File:   BigramDynamic.h
 * Author: Aziz OKAY
 *
 * Created on December 16, 2016, 9:42 AM
 */

#ifndef BIGRAMDYN_H
#define BIGRAMDYN_H

#include <iostream>
#include "Bigram.h"
#include <fstream>
#include "singleBigram.h"

using namespace std;


template <class T>
class BigramDyn;

template<class T>
ostream& operator<< ( ostream& out, const BigramDyn<T>& obj );

template<class T>
class BigramDyn : public Bigram<T>{
	public:
		BigramDyn();
		BigramDyn(int dType);
		BigramDyn(int dType, int theCapacity);
		~BigramDyn();

		int getCapacity( ) const { return capacity;}
		int getNumberUsed( ) const { return used;}


		void addBigram(const pair<T, T>& element);
		bool exist(const pair<T, T>& element);
		singleBigram<T>& operator[]( int index);
		singleBigram<T>& at(const pair<T, T>& element);
		bool full( ) const { return (capacity == used); }

		int numGrams();
		pair<T, T> maxGrams();
		int numOfGrams(T p1, T p2);
		int readFile(const char *fileName);
		friend ostream& operator << <>(ostream& out, const Bigram<T>& obj);

	private:
		int dType;
		singleBigram<T> *bigram;
		int capacity;
		int used;
		void bubble_sort();
		void swap(const int p1, const int p2);
		void fillMap(T elm1, T elm2);
		void print(ostream& out) const;
};

#endif /* BIGRAMDYN_H */
