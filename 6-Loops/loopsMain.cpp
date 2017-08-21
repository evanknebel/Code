#include <iostream>

int main()
{
/*
	int iter = 0;
// While
	while (iter <= 10)
	{
		std::cout << iter << std::endl;
		iter++;
	}

// For
	for (int iter = 0; iter <= 10; iter++)
	{
		std::cout << iter << std::endl;
	}

// Do while
	int j = 0;
	do
	{
		std::cout << j << std::endl;
		j++;
	} while (j <= 10);

// Simple input validation
	int userInput = 0;
	do
	{
		std::cout << "Give me a number between 1 and 5" << std::endl;
		std::cin >> userInput;
	} while (userInput < 1 || userInput > 5);
*/
/*
// From X to Y
	int X = 0;
	int Y = 0;

	std::cin >> X;
	std::cin >> Y;

	if (X < Y)
	{
		std::cout << X << std::endl;
		while (X < Y)
		{
			X++;
			std::cout << X << std::endl;
		}
	}
	else if (Y < X)
	{
		std::cout << Y << std::endl;
		while (Y < X)
		{
			Y++;
			std::cout << Y << std::endl;
		}
	}
*/
/*
// Fizz Buzz
	int X = 0;
	int Y = 0;

	std::cin >> X;
	std::cin >> Y;

	if (X < Y)
	{
		while (X <= Y)
		{
			if (X % 3 == 0)
			{
				if (X % 5 == 0)
				{
					std::cout << "FizzBuzz" << std::endl;
				}
				else
				{
					std::cout << "Fizz" << std::endl;
				}
			}
			else if (X % 5 == 0)
			{
				std::cout << "Buzz" << std::endl;
			}
			else
			{
				std::cout << X << std::endl;
			}
			X++;
		}
	}
	else if (Y < X)
	{
		while (Y <= X)
		{
			if (Y % 3 == 0)
			{
				if (Y % 5 == 0)
				{
					std::cout << "FizzBuzz" << std::endl;
				}
				else
				{
					std::cout << "Fizz" << std::endl;
				}
			}
			else if (Y % 5 == 0)
			{
				std::cout << "Buzz" << std::endl;
			}
			else
			{
				std::cout << Y << std::endl;
			}
			Y++;
		}
	}
*/

// Grid Generator
	int X = 0;
	int Y = 0;

	std::cin >> X;
	std::cin >> Y;

	for (int YBlocksPrinted = 0; YBlocksPrinted < Y; YBlocksPrinted++)
	{
		for (int XBlocksPrinted = 0; XBlocksPrinted < X; XBlocksPrinted++)
		{
			std::cout << "#";
		}
		std::cout << "" << std::endl;
	}


	system("pause");
}