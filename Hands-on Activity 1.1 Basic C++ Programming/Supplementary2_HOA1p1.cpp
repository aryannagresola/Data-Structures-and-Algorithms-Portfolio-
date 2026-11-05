#include <iostream>

double KelvinToFahrenheit(double kelvin);

int main(){
	double kelvin, fahrenheit;
	
	std::cout << "KELVIN TO FAHRENHEIT CONVERTER" << std::endl;
	std::cout << "Enter temperature in Kelvin: ";
	std::cin >> kelvin;
	
	if (kelvin < 0){
		std::cout << "Invalid input. Kelvin temperature cannot be negative. 
		Input new value." << std::endl;
	}
	else{
		fahrenheit = KelvinToFahrenheit(kelvin);
		std::cout << "Temperature in Fahrenheit: " << fahrenheit << "°F" << std::endl;
	}
	
	return 0;
}
double KelvinToFahrenheit(double kelvin){
	return (kelvin - 273.15) * 9/5 + 32; 
}




