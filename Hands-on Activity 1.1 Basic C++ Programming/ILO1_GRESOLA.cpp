#include <iostream>

//Function Prototype
void displaySum(int fNum, int sNum); 
bool valGreater(int A, int B); S
bool logicalOperations( bool a, bool b); 


int main(){
	int num1, num2;
	int A, B;
	bool a, b;
	
	std::cout << "GETTING THE SUM OF TWO NUMBERS" << std::endl;
	std::cout << "Enter first number: " << std::endl;
	std::cin >> num1;
	std::cout << "Enter second number: " << std::endl;
	std::cin >> num2;
	displaySum(num1, num2);
	std::cout << std::endl;
	
	std::cout << "COMPARING GREATER VALUE" << std::endl;
	std::cout << "Enter value A: " << std::endl;
	std::cin >> A;
	std::cout << "Enter value B: " << std::endl;
	std::cin >> B;
	std::cout << std::endl;SS
	
	if (valGreater(A,B)){
		std::cout << "A is greater than B. " << std::endl;
	}else
		std::cout << "A is NOT greater than B. " << std::endl;
	std::cout << std::endl;
	
	std::cout << "LOGICAL OPERATIONS" << std::endl;
	std::cout << "Enter first boolean value  (1 = True, 0 = False): " << std::endl;
	std::cin >> a;
	std::cout << "Enter second boolean value (1 = True, 0 = False): " << std::endl;
	std::cin >> b;
	
	if (logicalOperations(a,b))
		std::cout <<  "Logical Operations executed successfully." << std::endl;
		
	return 0;
}

//  Function Definition

void displaySum(int fNum, int sNum){
	std::cout << "The sum of the two number is: " << fNum + sNum << std::endl;
}
bool valGreater(int A, int B){
	return A > B;
}
bool logicalOperations(bool a, bool b){
	std::cout << "AND: " << (a && b) << std::endl;
	std::cout << "OR: " << (a || b) << std::endl;
	std::cout << "NOT a: " << (!a) << std::endl;
	std::cout << "NOT b: " << (!b) << std:: endl; 
	return true; 
}
