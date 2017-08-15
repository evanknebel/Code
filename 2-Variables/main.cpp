#include <iostream>

int main()
{
	int age = 1;
	std::cout << age << std::endl;
	age++;
	std::cout << age << std::endl;
	age++;
	std::cout << age << std::endl;
	//
	int first = 12;
	int second = 34;
	int sum = first + second;

	std::cout << first << "+" << second << "=" << sum << std::endl;
	//
	float third = 11.25;
	float fourth = 34.75;
	float sumOfFloats = third + fourth;

	std::cout << third << "+" << fourth << "=" << sumOfFloats << std::endl;
	system("pause");

	std::cout << "" << std::endl;
	//
	std::cout << "Time for your own math." << std::endl;
	std::cout << "Enter a couple numbers and we'll add them together." << std::endl;

	double userInputA;
	double userInputB;
	double sumOfUserInputs;

	std::cin >> userInputA;
	std::cin >> userInputB;
	sumOfUserInputs = userInputA + userInputB;

	std::cout << userInputA << "+" << userInputB << "=" << sumOfUserInputs << std::endl;
	system("pause");
	//
	std::cout << "" << std::endl;
	std::cout << "This next one converts Celcius temperatures to Fahrenheit." << std::endl;
	std::cout << "Enter a temperature now." << std::endl;
	double userInputTemp;
	double fahrenheitOutput;

	std::cin >> userInputTemp;
	fahrenheitOutput = userInputTemp * 9 / 5 + 32;

	std::cout << userInputTemp << " Celcius is " << fahrenheitOutput << " Fahrenheit." << std::endl;
	system("pause");
	//
	std::cout << "" << std::endl;
	std::cout << "This one finds the area of a rectangle from the width and height provided." << std::endl;
	std::cout << "Enter the width of your rectangle." << std::endl;

	double rectWidth;
	double rectHeight;
	double rectArea;

	std::cin >> rectWidth;
	std::cout << "Now the height." << std::endl;
	std::cin >> rectHeight;
	rectArea = rectHeight * rectWidth;
	std::cout << "The area of your rectangle is " << rectArea << "." << std::endl;
	system("pause");
	//
	double firstNumber;
	double secondNumber;
	double thirdNumber;
	double fourthNumber;
	double fifthNumber;
	double average;

	std::cout << "" << std::endl;
	std::cout << "Next we will find the average of 5 numbers you enter." << std::endl;
	std::cout << "Enter the first number." << std::endl;
	std::cin >> firstNumber;
	std::cout << "Now the second one." << std::endl;
	std::cin >> secondNumber;
	std::cout << "And the third." << std::endl;
	std::cin >> thirdNumber;
	std::cout << "Fourth." << std::endl;
	std::cin >> fourthNumber;
	std::cout << "And the last one." << std::endl;
	std::cin >> fifthNumber;
	average = (firstNumber + secondNumber + thirdNumber + fourthNumber + fifthNumber) / 5;
	std::cout << "The average of all your numbers is " << average << "." << std::endl;
	system("pause");

}