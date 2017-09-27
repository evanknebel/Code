#pragma once

#include <string>

class Person
{
protected:
	std::string fullName;

	int happiness;

public:
	Person();
	Person(std::string initialName, int initialHappiness);

	virtual void greet();

	bool isHappy();
};