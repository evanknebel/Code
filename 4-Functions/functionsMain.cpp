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

int clamp(double a)
{
	std::cout << "" << std::endl;
	int min = 15;
	int max = 30;
	if (a < min)
	{
		return min;
	}
	else if (a > max)
	{
		return max;
	}
	else
	{
		return a;
	}
}

int main()
{
	hello();
	std::cout << square(5);
	std::cout << decimal(2 , 5);
	std::cout << clamp(16);

	system("pause");

}