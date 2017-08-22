#include "piggyBank.h"
#include <iostream>

int main()
{
	piggyBank mine;
	mine.oneDollars = 19;
	mine.twoDollars = 5;
	mine.fiveDollars = 20;
	mine.quarters = 8;
	mine.dimes = 50;
	mine.nickels = 200;
	mine.pennies = 100;

	calcCoins(mine);
	calcBills(mine);
	calcTotal(mine);

	while (true);
}