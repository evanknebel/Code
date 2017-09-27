#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

// Prints text slowly in a string
void delay(int delay, std::string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		std::cout << text[i];
		Sleep(delay);
		if (text[i] == ',')
		{
			Sleep(100);
		}
		else if (text[i] == '.')
		{
			Sleep(500);
		}
	}
}

int main()
{
	std::fstream file;

	file.open("_TEST_.txt", std::ios_base::in);

	if (file.is_open())
	{
		std::cout << "Successfully opened file" << std::endl;

		std::string line;

		while (std::getline(file, line))
		{
			delay(25, line);
			std::cout << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "Could not find file" << std::endl;
	}


	system("pause");
	system("pause");
}