#include <iostream>


void evenOddNumberPickerer()
{
	int evenNumbers = 0;
	int oddNumbers = 0;

	std::cout << "Please enter the amount of numbers you will enter later" << std::endl;
	int numberOfNumbers;
	std::cin >> numberOfNumbers;
		for (int i = 1; i <= numberOfNumbers; i++)
		{
			std::cout << "What's number " << i << "?" << std::endl;
			int number = 0;
			std::cin >> number;
			if (number % 2 == 0)
			{
				evenNumbers++;
			}
			else if (number % 2 != 0)
			{
				oddNumbers++;
			}
		}
		
		if (evenNumbers > oddNumbers)
		{
			std::cout << "There were more even numbers" << std::endl;
		}
		else if (oddNumbers > evenNumbers)
		{
			std::cout << "There were more odd numbers" << std::endl;
		}
		else if (evenNumbers = oddNumbers)
		{
			std::cout << "There were the same amount of even and odd numbers" << std::endl;
		}
}

//for (int i = 0; i < 5; ++i)
//{
//
//}

int main()
{
	//int * numIntPointer = new int(25);
	//std::cout << *numIntPointer << std::endl;
	//delete numIntPointer;
	//float * numFloatPointer = new float(127.2);
	//std::cout << *numFloatPointer << std::endl;
	//delete numFloatPointer;
	//bool * boolPointer = new bool(true);
	//std::cout << *boolPointer << std::endl;
	//delete boolPointer;
	
	
	evenOddNumberPickerer();

	system("pause");
	system("pause");
}