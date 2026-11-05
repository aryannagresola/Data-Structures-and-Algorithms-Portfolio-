#include <iostream>
#include <cmath>

class Distance{
	private: 
		double x1, y1, x2, y2;
		
	public:
		//constructor
		Distance(double a, double b, double c, double d);
		double calculateDistance();
};

// the constructor definition
Distance::Distance(double a, double b, double c, double d) {
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}

// method definition
double Distance::calculateDistance(){
	 return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	 // formula to find the distance
}
int main(){
	double x1, y1, x2, y2;
	
	std::cout << "FINDING THE DISTANCE BETWEEN TWO POINTS" << std::endl;
	
	std::cout << "Enter x-coordinate of Point 1: ";
	std::cin >> x1;
	
	std::cout << "Enter y-coordinate of Point 1: ";
	std::cin >> y1;
	
    std::cout << "Enter x-coordinate of Point 2: ";
    std::cin >> x2;

    std::cout << "Enter y-coordinate of Point 2: ";
    std::cin >> y2;
	
	Distance point(x1, y1, x2, y2);
	
	std::cout << std::endl;
	std::cout << "DISTANCE = " << point.calculateDistance() << std::endl;
	
	return 0;
}
