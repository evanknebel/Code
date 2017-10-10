# include "mathUtilities.h"

int minOfTwo(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
	
//	return a < b ? a : b;
}

int maxOfTwo(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}

//	return a > b ? a : b;
}