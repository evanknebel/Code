#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::fstream file;
	file.open("anInsult.txt");

	if (file.fail())
	{
		std::cerr << "File not found." << std::endl;
	}

	std::string buffer;
	while (std::getline("anInsult.txt", buffer))  // iterates until error or EOF
	{
		// print the line after it is buffered
		std::cout << buffer << std::endl;
	}







	system("pause");
	system("pause");
}