#include <iostream>

void printNumbers(int nums[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << nums[i] << std::endl;
	}
}



int main()
{
	int values[]{1, 3, 5, 7, 9};

	printNumbers(values, 5);

	system("pause");
}








