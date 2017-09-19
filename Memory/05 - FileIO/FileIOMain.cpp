#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream file;

	file.open("aCompliment.txt", std::ios_base::in);

	if (file.is_open())
	{
		std::cout << "Successfully opened file" << std::endl;

		char line[100];

		while (file.peek() != EOF)
		{
			file.getline(line, 100);
			std::cout << line << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "Could not find file" << std::endl;
	}
	file.open("anInsult.txt", std::ios_base::in);

	if (file.is_open())
	{
		std::cout << "Successfully opened file" << std::endl;

		char line[100];

		while (file.peek() != EOF)
		{
			file.getline(line, 100);
			std::cout << line << std::endl;
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