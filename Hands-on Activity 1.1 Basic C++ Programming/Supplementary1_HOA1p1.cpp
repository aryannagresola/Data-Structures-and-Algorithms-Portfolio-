#include <iostream>

void swapNum(int &num1, int &num2); //& means pass by reference. 

int main(){
	int fNum, sNum;
	
	std::cout << "SWAP NUMBERS" << std::endl;
	std::cout << "Enter first number: ";
	std::cin >> fNum;
	std::cout << "Enter second number: ";
	std::cin >> sNum;
	std::cout << std::endl;
	
	// for a comparison
	std::cout << "BEFORE SWAPPING" << std::endl;
	std::cout << "First number: " << fNum << std::endl;
	std::cout << "Second number: " << sNum << std::endl;
	std::cout << std::endl;
	
	swapNum(fNum, sNum);
	
	std::cout << "AFTER SWAPPING" << std::endl;
	std::cout << "First number: " << fNum << std::endl;
	std::cout << "Second number: " << sNum << std::endl;
	
	return 0;
}
void swapNum(int &num1, int &num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}


