#include "piggyBank.h"
#include <iostream>

void calcTotal(piggyBank mine)
{
	float totalWealth = (mine.oneDollars + (mine.twoDollars * 2) + (mine.fiveDollars * 5) + (mine.quarters * 0.25) + (mine.dimes * 0.1) + (mine.nickels * 0.05) + (mine.pennies * 0.01));
	std::cout << "Total money in my own piggy bank is: $" << totalWealth << std::endl;
}
void calcCoins(piggyBank mine)
{
	float totalCoins = ((mine.quarters * 0.25) + (mine.dimes * 0.1) + (mine.nickels * 0.05) + (mine.pennies * 0.01));
	std::cout << "Total money in my own piggy bank in coins is: $" << totalCoins << std::endl;
}
void calcBills(piggyBank mine)
{
	float totalBills = (mine.oneDollars + (mine.twoDollars * 2) + (mine.fiveDollars * 5));
	std::cout << "Total money in my own piggy bank in bills is: $" << totalBills << std::endl;
}