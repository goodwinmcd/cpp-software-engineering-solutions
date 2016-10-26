/**Solution to problem 1 at http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour.
*Problem statement: Write three functions that compute the sum of the numbers in a given list using a for-loop, a while-loop, and recursion.
*Author: Goodwin McDonald 
*/

#include <iostream>

class listSolver{
	private:
	    int arraySize;
	    int *address;
	    int addNumbers(int *numAddress,int num, int count);
	public:
	    listSolver(int *arrayAddress, int size);
	    ~listSolver();
	    int forLoopSolver();
	    int whileLoopSolver();
	    int recursiveSolver();
};

listSolver::listSolver(int *arrayAddress,int size){
	arraySize = size;
	address = arrayAddress;
}

listSolver::~listSolver(){
}

int listSolver::forLoopSolver(){
	int solution = 0;
	int *funcAddress = address;
	for(int i=0; i<arraySize; i++){
		std::cout<<"The current number is "<<*funcAddress<<"\n";
		solution+=*funcAddress;
		funcAddress+=1;
	}
	return solution;
}

int listSolver::whileLoopSolver(){
	int counter = 0;
	int solution = 0;
	int *funcAddress = address;
	while(counter<arraySize){
		std::cout<<"The current number is "<<*funcAddress<<"\n";
		solution+=*funcAddress;
		std::cout<<"The current solution is "<<solution<<"\n";
		funcAddress+=1;
		std::cout<<"The counter is "<<counter<<" and the array size is "<<arraySize<<"\n";
		counter+=1;
	}
	return solution;
}

int listSolver::recursiveSolver(){
	int *funcAddress = address;
	int size = arraySize;
	int solution = 0;
	solution = listSolver::addNumbers(funcAddress,solution,size);
	return solution;
}

int listSolver::addNumbers(int *numAddress,int num, int count){
	if(count == 0){
		return num+*numAddress;
	}
	else{
		std::cout<<"The current number is: "<<num<<"\n";
		count--;
		num+=*numAddress;
		numAddress++;
		return addNumbers(numAddress,num,count);
	}
}

int main(){
	int answer;
	int myArray[5] = {10, 20,25,30,40};
	int *pointer = myArray;
	listSolver mySolver(pointer, 5);
	std::cout<<"The answer for the for loop is: "<<mySolver.forLoopSolver()<<"\n";
	std::cout<<"The answer for the while loop is "<<mySolver.whileLoopSolver()<<"\n";
	std::cout<<"The answer for the recursive loop is "<<mySolver.recursiveSolver()<<"\n";
}
