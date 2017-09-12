#include <iostream>

void printNumbers(int nums[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << nums[i] << std::endl;
	}
}

int sumNumbers(int num[], int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total = total + num[i];
	}
	std::cout << total << std::endl;
	return total;
}

void reverse(int num[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = num[i];
		//front to back
		num[i] = num[size - 1 - i];
		//back to front
		num[size - 1 - i] = temp;
	}
}

//void sortAscend(int num[], int size)
//{
//	while (true)
//	{
//		bool isSorted = true;
//		for (int i = 0; )
//	}
//}

int main()
{
	int values[]{3, 5, 1, 2, 4};

	printNumbers(values, 5);
	sumNumbers(values, 5);
	reverse(values, 5);
	printNumbers(values, 5);
	reverse(values, 5);


	system("pause");
}