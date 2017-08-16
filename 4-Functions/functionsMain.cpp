#include <iostream>

 void hello()
{
	std::cout << "Hello functions.";
}

int square(int valueToBeSquared)
{
	std::cout << "" << std::endl;
	return valueToBeSquared * valueToBeSquared;
}

double decimal(double a, double b)
{
	std::cout << "" << std::endl;
	return a / b;
}

int main()
{
	hello();
	std::cout << square(5);
	std::cout << decimal(2 , 5);

	system("pause");


}