/*Solution to problem 2 at http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour
*Problem statement: Write a function that combines two lists by alternatingly taking elements. For example: given the two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c, 3].
*/
#include <iostream>

class arrayCombine{
	private:
	 int arraySize;
	 int* array1Addr;
	 int* array2Addr;
	 int* array3Addr;
	public:
	 arrayCombine(int* array1, int* array2, int size);
	 void printArray();
	 int* combine();
};

arrayCombine::arrayCombine(int* array1, int* array2, int size){
	array1Addr = array1;
	array2Addr = array2;
	arraySize = size;
	array3Addr = new int[2*size];
}

int* arrayCombine::combine(){
	int *array1Addrtemp = array1Addr;
	int *array2Addrtemp = array2Addr;
	int *array3Addrtemp = array3Addr;

	for(int i=0; i<arraySize; i++){
		std::cout<<"Current element in array1 is: "<<*array1Addrtemp<<"\n";
		std::cout<<"Current element in array2 is: "<<*array2Addrtemp<<"\n";
		*array3Addrtemp = *array1Addrtemp;
		std::cout<<"First element in array3 is: "<<*array3Addrtemp<<"\n";
		array3Addrtemp++;
		*array3Addrtemp = *array2Addrtemp;
		std::cout<<"Second element in array3 is: "<<*array3Addrtemp<<"\n";
		array3Addrtemp++;
		array1Addrtemp++;
		array2Addrtemp++;
	}
}
void arrayCombine::printArray(){
	int *array3Addrtemp = array3Addr;	
	for(int i=0; i<2*arraySize;i++){
		std::cout<<*array3Addrtemp<<"\n";
		array3Addrtemp++;
	}
}


int main(){
	int array1[] = {1,3,5,7};
	int array2[] = {2,4,6,8};
	arrayCombine myClass(array1,array2,4);
	myClass.combine();
	myClass.printArray();
	return 1;
}
