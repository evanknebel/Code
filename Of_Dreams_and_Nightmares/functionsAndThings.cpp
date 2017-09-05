#include <iostream>
#include <thread>
#include <Windows.h>
#include "functionsAndThings.h"


// Prints text slowly in a string
void delay(int delay, std::string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		std::cout << text[i];
		Sleep(delay);
	}
}