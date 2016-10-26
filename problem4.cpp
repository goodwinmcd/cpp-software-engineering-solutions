/*Solution to problem 4 at http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour.
*Problem statement: Write a function that given a list of non negative integers, arranges them such that they form the largest possible number. For 
*example, given [50, 2, 1, 9], the largest formed number is 95021.
*/

#include <iostream>
#include <cmath>

class largestNum{
	private:
	  int *array;
	  int *array2;
	  int size;
	  int *arrayOfDigits;
	  int getDigit(int num, int digitPlace);
	  int getNumberOfDigits(int num);
	  int* getDigitArray(int num);
	  void switchElements(int *num1, int *num2);
	public:
	  largestNum(int *array,int arraySize);
	  void printArray();
	  void findLargest();
};

largestNum::largestNum(int *passedArray, int arraySize){
	size = arraySize;
	array = passedArray;
	array2 = new int[size];
}

void largestNum::printArray(){
	int *index = array;
	for(int i=0; i<size; i++){
		std::cout<<*index<<"\n";
		index++;
	}
}

void largestNum::findLargest(){
	int *index1 = array;
	int *index2 = array;
	int digitCurrent;
	int digitCountNext;
	int digitCountCurrent;
	int smallerDigitCount;
	int digitNext;
	int nextNum;
	int temp;
	int loopCounter;
	int currentNum = *index1;
	nextNum = *index1;
	for(int i=0;i<size; i++){
		for (int j=i; j<size; j++){
			std::cout<<"Evaluating: "<<currentNum<<"(currentNum) and "<<nextNum<<" (nextNum)\n";
			digitCountNext = getNumberOfDigits(nextNum);
			digitCountCurrent = getNumberOfDigits(currentNum);

			int *currentNumDigitArray = getDigitArray(currentNum);
			currentNumDigitArray += digitCountCurrent-1;
			int *nextNumDigitArray = getDigitArray(nextNum);
			nextNumDigitArray += digitCountNext-1;

			if(digitCountNext >= digitCountCurrent){
				smallerDigitCount = digitCountCurrent;
			}
			else{
				smallerDigitCount = digitCountNext;
			}

			for(int i=0; i<smallerDigitCount; i++){
				if(*currentNumDigitArray-i != *nextNumDigitArray-i){
					digitCurrent = *currentNumDigitArray;
					digitNext = *nextNumDigitArray;;
					if(digitNext > digitCurrent){
						switchElements(index1,index2);
//                                		temp = *index1;
//                              		*index1 = *index2;
//                                		*index2 = temp;
                                		currentNum = *index1;
						break;
                        		}
				}
				if(*currentNumDigitArray-i == *nextNumDigitArray-i && i==smallerDigitCount-1){
					if(smallerDigitCount = digitCountNext){
						switchElements(index1,index2);
                                		currentNum = *index1;	
					}
				}
			}
			index2++;
			nextNum = *index2;
			}
		std::cout<<"Value of index1: "<<index1<<"\n";
		index1++;
		index2 = index1;
		currentNum = *index1;
		nextNum = *index1;
		printArray();
		std::cout<<"||||||||||||||||||||||||||||||||\n";
		}
}

void largestNum::switchElements(int *num1, int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int largestNum::getNumberOfDigits(int num){
	int count=1;
	if(num<10){
		return count;
	}
	else{
		while(num>10){
			num = num/10;
			count++;
		}
		return count;
	}
}
int* largestNum::getDigitArray(int num){
	int numOfDigits = getNumberOfDigits(num);
	arrayOfDigits = new int(numOfDigits);
	int digit;
	for(int i=0; i<numOfDigits;i++){
		digit = num % 10;
		num = num / 10;
		arrayOfDigits[i] = digit;
	}
	return arrayOfDigits;
}

int main(){
	int array[9] = {34,12, 9, 88, 44, 987,1145,5734,114};
	largestNum myObj(array,9);
	myObj.printArray();
	myObj.findLargest();
	myObj.printArray();
	return 1;
}
