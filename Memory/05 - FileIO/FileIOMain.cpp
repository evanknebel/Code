#include <iostream>
#include <fstream>
#include <Windows.h>

// Prints text slowly in a string
void delay(int delay, std::string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		std::cout << text[i];
		Sleep(delay);
	}
}

int main()
{
	std::fstream file;

	file.open("_TEST_.txt", std::ios_base::in);

	if (file.is_open())
	{
		std::cout << "Successfully opened file" << std::endl;

		char line[500];

		while (file.peek() != EOF)
		{
			file.getline(line, 9999999999);
			delay(20, line);
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