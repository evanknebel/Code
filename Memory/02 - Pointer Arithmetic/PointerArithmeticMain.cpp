#include <iostream>

void reverse(int nums[], int size)
{
	//printing the original order
	for (int i = 0; i < size; ++i)
	{
		std::cout << nums[i] << std::endl;
	}
	std::cout << "" << std::endl;
	//reversing the order
	for (int i = 0; i < size / 2; i++)
	{
		int temp = nums[i];
		//front to back
		nums[i] = nums[size - 1 - i];
		//back to front
		nums[size - 1 - i] = temp;
	}
	//printing the reversed order
	for (int i = 0; i < size; ++i)
	{
		std::cout << nums[i] << std::endl;
	}
	std::cout << "" << std::endl;
}

int main()
{
	int values[]{ 1, 2, 3, 4, 5 };
	reverse(values, 5);
	system("pause");
	system("pause");
}