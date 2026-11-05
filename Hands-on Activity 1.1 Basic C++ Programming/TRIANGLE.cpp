#include <iostream>
#include <cmath>

// naming convention for class name: PascalCase
class Triangle{
	private:
		double totalAngle, angleA, angleB, angleC;
		double sideA, sideB, sideC;

	public:
		//constructor
		Triangle(double A, double B, double C, double a);

		void setAngles(double A, double B, double C, double a);
		const bool validateTriangle();

		//a. computes area
		double computeArea();

		//b. computes perimeter of a triangle
		double computePerimeter();

		//c. determine the type of a triangle
		void triangleType();
};

int main(){

	double A, B, C, a;

	std::cout << "Enter Angle A: ";
	std::cin >> A;
	std::cout << "Enter Angle B: ";
	std::cin >> B;
	std::cout << "Enter Angle C: ";
	std::cin >> C;
	std::cout << "Enter Side A: ";
	std::cin >> a;
	// using the law of Sines
	
	Triangle set1(A, B, C, a);

	if(set1.validateTriangle()){

		std::cout << "\nThe shape is a valid triangle.\n";

		//4a. display the area
		std::cout << "Area: " << set1.computeArea() << std::endl;

		//4b. display the perimeter
		std::cout << "Perimeter: " << set1.computePerimeter() << std::endl;

		//4c. display the type of triangle
		std::cout << "Triangle Type: ";
		set1.triangleType();
	}
	else{
		std::cout << "\nThe shape is NOT a valid triangle.";
	}

	return 0;
}

//constructor
Triangle::Triangle(double A, double B, double C, double a){

	angleA = A;
	angleB = B;
	angleC = C;
	sideA = a;

	totalAngle = A + B + C;

	//compute the remaining sides if the triangle is valid
	if(validateTriangle()){

		sideB = sideA * sin(angleB * 3.14159265358979323846 / 180)
		              / sin(angleA * 3.14159265358979323846 / 180);

		sideC = sideA * sin(angleC * 3.14159265358979323846 / 180)
		              / sin(angleA * 3.14159265358979323846 / 180);
	}
}

//set angles
void Triangle::setAngles(double A, double B, double C, double a){

	angleA = A;
	angleB = B;
	angleC = C;
	sideA = a;

	totalAngle = A + B + C;

	//recompute the remaining sides if the triangle is valid
	if(validateTriangle()){

		sideB = sideA * sin(angleB * 3.14159265358979323846 / 180)
		              / sin(angleA * 3.14159265358979323846 / 180);

		sideC = sideA * sin(angleC * 3.14159265358979323846 / 180)
		              / sin(angleA * 3.14159265358979323846 / 180);
	}
}

//validate triangle
const bool Triangle::validateTriangle(){

	return(totalAngle == 180);
}

//compute area
double Triangle::computeArea(){

	return 0.5 * sideB * sideC *
	       sin(angleA * 3.14159265358979323846 / 180);
}

//compute perimeter
double Triangle::computePerimeter(){

	return sideA + sideB + sideC;
}

//c. function that determine the type of a triangle
void Triangle::triangleType(){

	//acute triangle
	if(angleA < 90 && angleB < 90 && angleC < 90){
		std::cout << "Acute-angled Triangle";
	}
	//obtuse triangle
	else if(angleA > 90 || angleB > 90 || angleC > 90){
		std::cout << "Obtuse-angled Triangle";
	}
	//others
	else{
		std::cout << "Others";
	}
}
