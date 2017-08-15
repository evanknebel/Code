#include <iostream>

int main()
{
// The following desctibes a number as large or small realitively to 50
	/*
		double sizeNumber;
		std::cout << "Enter a number, and I'll tell you how big it is. " << std::endl;
		std::cin >> sizeNumber;
		if (sizeNumber > 50)
		{
			std::cout << sizeNumber << " is pretty big. ";
		}
		else if (sizeNumber == 50)
		{
			std::cout << sizeNumber << " is a very balanced number. ";
		}
		else
		{
			std::cout << sizeNumber << " is kinda small. ";
		}
		system("pause");

		std::cout << "" << std::endl;
	*/
// The following compairs the sizes of three numbers and outputs the smallest
	/*
	double comparisonNumberA;
	double comparisonNumberB;
	double comparisonNumberC;

	std::cout << "Now enter 3 numbers and I'll identify the smallest one. " << std::endl;

	std::cin >> comparisonNumberA;
	std::cin >> comparisonNumberB;
	std::cin >> comparisonNumberC;

	if (comparisonNumberA == comparisonNumberB)
	{
		if (comparisonNumberA < comparisonNumberC)
		{
			std::cout << "The smallest number is " << comparisonNumberA << ". ";
		}
		else if (comparisonNumberC < comparisonNumberA && comparisonNumberB)
		{
			std::cout << "The smallest number is " << comparisonNumberC << ". ";
		}
	}
	else if (comparisonNumberB == comparisonNumberC)
	{
		if (comparisonNumberB < comparisonNumberA)
		{
			std::cout << "The smallest number is " << comparisonNumberB << ". ";
		}
		else if (comparisonNumberA < comparisonNumberB && comparisonNumberC)
		{
			std::cout << "The smallest number is " << comparisonNumberA << ". ";
		}
	}
	else if (comparisonNumberA == comparisonNumberC)
	{
		if (comparisonNumberA < comparisonNumberB)
		{
			std::cout << "The smallest number is " << comparisonNumberA << ". ";
		}
		else if (comparisonNumberB < comparisonNumberA && comparisonNumberC)
		{
			std::cout << "The smallest number is " << comparisonNumberB << ". ";
		}
	}
	else
	{
		if (comparisonNumberA < comparisonNumberB && comparisonNumberC)
		{
			std::cout << "The smallest number is " << comparisonNumberA << ". ";
		}
		else if (comparisonNumberB < comparisonNumberA && comparisonNumberC)
		{
			std::cout << "The smallest number is " << comparisonNumberB << ". ";
		}
		else if (comparisonNumberC < comparisonNumberA && comparisonNumberB)
		{
			std::cout << "The smallest number is " << comparisonNumberC << ". ";
		}
	}
	system("pause");
	*/
// The following determines if a whole number is even or odd
	/*
	std::cout << "This will determine if a whole number you enter is even or odd." << std::endl;
	std::cout << "Enter a number now." << std::endl;

	int evenOrOddNumber;
	std::cin >> evenOrOddNumber;

	if (evenOrOddNumber % 2 == 0)
	{
		std::cout << evenOrOddNumber << " is even." << std::endl;
	}
	else if (evenOrOddNumber % 2 == 1)
	{
		std::cout << evenOrOddNumber << " is odd." << std::endl;
	}
	system("pause");
	*/
// The following clamps the user input number to a value between 15 and 30
	/*
	std::cout << "This limits your number to a value between 15 and 30." << std::endl;
	std::cout << "Enter a number now, and it will be replaced if needed." << std::endl;
	
	double clampNumber;
	std::cin >> clampNumber;

	if (clampNumber > 30)
	{
		clampNumber = 30;
	}
	if (clampNumber < 15)
	{
		clampNumber = 15;
	}
	std::cout << clampNumber << std::endl;
	system("pause");
	*/



}