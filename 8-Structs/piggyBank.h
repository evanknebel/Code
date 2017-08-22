#pragma once

struct piggyBank
{
	int oneDollars;
	int twoDollars;
	int fiveDollars;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
};

void calcTotal(piggyBank mine);
void calcCoins(piggyBank mine);
void calcBills(piggyBank mine);