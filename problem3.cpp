/**Solution to problem 3 at http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour.
*Problem statement: Write a function that computes the list of the first 100 Fibonacci numbers. By definition, the first two numbers in the Fibonacci 
*sequence are 0 and 1, and each subsequent number is the sum of the previous two. As an example, here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 
*5, 8, 13, 21, and 34.
*/

#include <iostream>

class fibonacci{
	private:
	  long double num1;
	  long double num2;
	  long double num3;
	public:
	  fibonacci();
	  void printFibonacci(int limit);
};

fibonacci::fibonacci(){
	num1 = 0;
	num2 = 1;
}

void fibonacci::printFibonacci(int limit){
	std::cout<<num1<<"\n"<<num2<<"\n";
	long double temp;
	for(int i=0; i<limit;i++){
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
		std::cout<<num3<<"\n";
	}
}

int main(){
	fibonacci myFib;
	myFib.printFibonacci(100);
	return 1;
}

