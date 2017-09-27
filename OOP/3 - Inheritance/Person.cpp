#include "Person.h"
#include <iostream>

Person::Person()
{
	fullName = "";
	happiness = 50;
}

Person::Person(std::string initialName, int initialHappiness)
{
	fullName = initialName;
	happiness = initialHappiness;
}

void Person::greet()
{
	std::cout << "Howdy! My name is " << fullName << "." << std::endl;
}

bool Person::isHappy()
{
	return happiness > 70;
}