
#include "singleBigram.h"



template <class T>
singleBigram<T>::singleBigram( const singleBigram<T>& object) {
	setFirst(object.getFirst());
	setSecond(object.getSecond());
	setNumOfGrams(object.getNumOfGrams());
}
