#include <iostream>

 int hello()
{
	std::cout << "Hello functions.";
	return 0;
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
	std::cout << hello();
	std::cout << square(5);
	std::cout << decimal(2 , 5);

	system("pause");


}