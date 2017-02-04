/*
 * File:   BigramDynamic.cpp
 * Author: Aziz OKAY
 *
 * Created on December 16, 2016, 9:42 AM
 */

#include "BigramDyn.h"

/* No parameter constructor*/
template < class T>
BigramDyn<T>::BigramDyn( ) :capacity(50), used(0) {
	bigram = new singleBigram<T>[capacity];
}

/* Destructor for bigram dynamic */
template < class T>
BigramDyn<T>::~BigramDyn() {
	delete [] bigram;
}


template < class T>
void BigramDyn<T>::bubble_sort() {
	bool swapped = true;
    int j = 0;

    while (swapped) {
		swapped = false;
        j++;
        for (int i = 0; i < used - j; i++) {
        	if (bigram[i].getNumOfGrams() < bigram[i + 1].getNumOfGrams()) {
            	swap(i, i + 1);
                swapped = true;
            }
        }
	}
}


/* one parameter constructor*/
template < class T>
BigramDyn<T>::BigramDyn(int type) :capacity(50), used(0) {
	dType = type;
	bigram = new singleBigram<T>[capacity];
}

/* two(a type and size) parameter constructor*/
template < class T>
BigramDyn<T>::BigramDyn(int type, int theCapacity) :capacity(theCapacity), used(0) {
	dType = type;
	bigram = new singleBigram<T>[capacity];
}

/* add a pair to bigarm */
template<class T>
void BigramDyn<T>::addBigram(const pair<T, T>& element) {

	if (used >= capacity) {

		singleBigram<T> temp[getCapacity() + 50];
		for(int i = 0; i < used; i++) {
			temp[i].setFirst(bigram[i].getFirst());
			temp[i].setSecond(bigram[i].getSecond());
			temp[i].setNumOfGrams(bigram[i].getNumOfGrams());
		}

		delete [] bigram;
		capacity = getCapacity() + 50;
		bigram = new singleBigram<T>[capacity];

		for(int i = 0; i < used; i++) {
			bigram[i].setFirst(temp[i].getFirst());
			bigram[i].setSecond(temp[i].getSecond());
			bigram[i].setNumOfGrams(temp[i].getNumOfGrams());
		}
	}
	bigram[used].setFirst(element.first);
	bigram[used].setSecond(element.second);
	bigram[used].setNumOfGrams(1);
	used++;
}

template<class T>
void BigramDyn<T>::swap(const int p1, const int p2) {
	singleBigram<T> temp;
	temp.setFirst(bigram[p1].getFirst());
	temp.setSecond(bigram[p1].getSecond());
	temp.setNumOfGrams(bigram[p1].getNumOfGrams());
	bigram[p1].setFirst(bigram[p2].getFirst());
	bigram[p1].setSecond(bigram[p2].getSecond());
	bigram[p1].setNumOfGrams(bigram[p2].getNumOfGrams());
	bigram[p2].setFirst(temp.getFirst());
	bigram[p2].setSecond(temp.getSecond());
	bigram[p2].setNumOfGrams(temp.getNumOfGrams());
}


/* function check if given pair exist or not*/
template<class T>
bool BigramDyn<T>::exist(const pair<T, T>& element) {
	for (int i = 0; i < used; i++) {
    	if ( bigram[i].getFirst() == element.first && bigram[i].getSecond() == element.second)
    		return true;
    }
    return false;
}

/* function that return referance of Bigram that match given pair ***/
template<class T>
singleBigram<T>& BigramDyn<T>::at(const pair<T, T>& element) {
	try {
		if (!exist(element))
			throw element;
		for (int i = 0; i < used; i++) {
			if ( bigram[i].getFirst() == element.first && bigram[i].getSecond() == element.second)
				return bigram[i];
		}
	}catch (pair<T, T>& e){
		cout << "The Pair (" << e.first << " , " << e.second << ") does not exist.\n";
		cout << "The return value will could be NULL\n";
		return bigram[0];
    }
}


/* operator overloading [] that retured a bigram*/
template <class T>
singleBigram<T>& BigramDyn<T>::operator[]( int index) {
	try {
		if (index >= used)
			throw index;

		return bigram[index];
	}
	catch(int e) {
		cout << "The " << e << "out of Bigram Dynamic!!\n";
		cout << "The return value will be NULL!!!\n" ;
		return NULL;

	}
}

/* function that read file and save all bigram ***/
template < class T>
int BigramDyn<T>::readFile(const char *fileName) {
    ifstream inputStream;
    T temp1, temp2;
    int counter = 0;
    inputStream.open(fileName);
	try {
		if(!inputStream.is_open())
			throw 0;
		    while( inputStream >> temp1 ) {
		        if ( counter > 0 ) {
		    		fillMap(temp2, temp1);
		        }
		        temp2 = temp1;
		        counter++;
		    }
			if (counter == 0)
	            throw 1;
			bubble_sort();
		    return 1;

	} catch (int e) {
		if (e == 0)
            cerr << "Error opening file!!!" << endl;
        else if (e == 1)
            cerr << "File is empty!!" << endl;
    }
    inputStream.close();
}

/* function fill dynamic map with bigram */
template < class T>
void BigramDyn<T>::fillMap(T elm1, T elm2) {
	pair<T, T> MyPair;
    MyPair = std::make_pair(elm1, elm2);

    if( exist(MyPair) ) {
    	at(MyPair).setNumOfGrams(at(MyPair).getNumOfGrams() + 1);
    }else {
    	addBigram(MyPair);
    }
}

/* function that returns number of all bigram*/
template < class T>
int BigramDyn<T>::numGrams() {
    return getNumberUsed( );
}

/* function taht returns number of given pair */
template < class T>
int BigramDyn<T>::numOfGrams(T p1, T p2) {
	pair<T, T> aPair;
    aPair = std::make_pair(p1, p2);
    try {
    	if (!exist(aPair))
    		throw aPair;
		for (int i = 0; i < used; i++) {
			if ( bigram[i].getFirst() == aPair.first && bigram[i].getSecond() == aPair.second)
				return bigram[i].getNumOfGrams();
		}
	}catch (pair<T, T> e){
		cout << "The Pair (" << e.first << " , " << e.second << ") does not exist.\n";
		cout << "The return value will could be 0.\n";
		return 0;
	}
}

/* function return bigram that most occoruamce in map*/
template < class T>
pair<T, T> BigramDyn<T>::maxGrams() {
    int max1 = 0, max2 = 0;
    T p1, p2;

    for (int i = 0; i < used; i++) {
        max1 = bigram[i].getNumOfGrams();
        if ( max1 > max2) {
            max2 = max1;
            p1 = bigram[i].getFirst();
            p2 = bigram[i].getSecond();
        }
    }

    return make_pair(p1, p2);
}

/* function oure virtual function helper for << opeator*/
template < class T>
void BigramDyn<T>::print(ostream& out) const{
    for (int i = 0; i < used; i++)
        cout << "(" << bigram[i].getFirst() << " , " << bigram[i].getSecond() << ")" << " => " << bigram[i].getNumOfGrams() << '\n';
}

/* overloading << for bigram dynamic map ***/
template < class T>
ostream& operator <<(ostream& out, const BigramDyn<T>& obj) {

    obj.print(out);
    return out;
}
