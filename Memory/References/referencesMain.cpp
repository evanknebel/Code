#include <iostream>

int variable = 15;
int& variable2 = variable;


int sum(int a, int b, int c)
{
	std::cin >> a;
	std::cin >> b;
	c = a + b;
	std::cout << c << std::endl;
	return c;
}

void swap(float a, float b)
{
	float storage = 0;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	storage = a;
	a = b;
	b = storage;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}




int main()
{
	//std::cout << variable << std::endl;
	//std::cout << variable2 << std::endl;

	//variable = 10;
	//std::cout << variable << std::endl;
	//std::cout << variable2 << std::endl;

	//variable2 = 5;
	//std::cout << variable << std::endl;
	//std::cout << variable2 << std::endl;

	//sum(0, 0, 0);

	swap(15.7, 75);

	system("pause");
	system("pause");
}
