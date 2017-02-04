/*
 * File:   BigramMap.cpp
 * Author: Aziz OKAY
 *
 * Created on December 16, 2016, 9:42 AM
 */


#include "BigramMap.h"

template < class T>
int BigramMap<T>::readFile(const char *fileName) {
    ifstream inputStream;
    T temp1, temp2;
    int counter = 0;
    inputStream.open(fileName);

	try {
    	if(!inputStream.is_open())
    		throw 0;

        while( inputStream >> temp1 ) {
            if (counter > 0 ) {
        	    fillMap(temp2, temp1);
            }
            temp2 = temp1;
            counter++;
        }
        if (counter == 0)
            throw 1;
        return 1;
    }catch (int e) {
        if (e == 0)
            cerr << "Error opening file!!!" << endl;
        else if (e == 1) {
            cerr << "File is empty!!" << endl;
        }

        return 0;
    }
    inputStream.close();
}

template < class T>
void BigramMap<T>::fillMap(T elm1, T elm2) {
    typename map<pair<T, T>, int>::iterator it;
    pair<T, T> MyPair;
    MyPair = std::make_pair(elm1, elm2);
    it = bigram.find(MyPair);

    if (it == bigram.end()) {
        bigram.insert(make_pair(MyPair, 1));
    }else {
        bigram[MyPair] = it->second + 1;
    }
}


template < class T>
int BigramMap<T>::numGrams() {
    return bigram.size();
}

template < class T>
int BigramMap<T>::numOfGrams(T p1, T p2) {
    typename map<pair<T, T>, int>::iterator it;
    pair<T, T> MyPair;
    MyPair = std::make_pair(p1, p2);
    it = bigram.find(MyPair);
    try {
    	if (it == bigram.end())
    		throw 0;

    	return it->second;
    } catch (int e) {
		cerr << "EXCEPTİON : Given pair does not exist in map" << endl;
		return 0;
    }

}


template < class T>
pair<T, T> BigramMap<T>::maxGrams() {
    int max1 = 0, max2 = 0;
    T p1, p2;
    typename map<pair<T, T>, int>::const_iterator it;

    for (it = bigram.begin(); it != bigram.end(); ++it) {
        max1 = it->second;
        if ( max1 > max2) {
            max2 = max1;
            p1 = it->first.first;
            p2 = it-> first.second;
        }
    }

    return make_pair(p1, p2);
}

template < class T>
void BigramMap<T>::print(ostream& out) const {
    typename map<pair<T, T>, int>::const_iterator it;
    for (it = bigram.begin(); it != bigram.end(); ++it)
        cout << "(" << it->first.first << " , " << it-> first.second << ")" << " => " << it->second << '\n';
}


template < class T>
ostream& operator <<(ostream& out, const Bigram<T>& obj) {
    obj.print(out);
    return out;
}
