// Returns the lesser of two integers.
int min(int a, int b)
{
	if (a <= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
// Returns the greater of two integers.
int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
// Returns a value clamped within a range.
int clamp(int min, int max, int a)
{
	if (a < min)
	{
		return min;
	}
	else if (a > max)
	{
		return max;
	}
	else
	{
		return a;
	}
}

// Returns the distance between two points.
float dist(float x1, float y1, float x2, float y2);
