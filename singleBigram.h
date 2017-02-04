#ifndef SINGLEBIGRAM_H
#define SINGLEBIGRAM_H


template<class T>
class singleBigram {



	public:
		singleBigram() : numOfGrams(0) {}
		singleBigram(T elm1, T elm2) : first(elm1), second(elm2), numOfGrams(0) {}
		singleBigram(T elm1, T elm2, int num) : first(elm1), second(elm2), numOfGrams(num) {}

		singleBigram( const singleBigram<T>& object);

		T getFirst() const { return first;}
		T getSecond() const { return second;}
		int getNumOfGrams() const { return numOfGrams;}

		void setFirst(const T newFirst) { first = newFirst; }
		void setSecond(const T newSecond) { second = newSecond; }
		void setNumOfGrams(const int number) { numOfGrams = number; }


	private:
		T first;
		T second;
		int numOfGrams;
};
#endif /* SINGLEBIGRAM_H */
