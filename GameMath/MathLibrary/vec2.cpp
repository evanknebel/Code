#include "vec2.h"

#include <cmath>
#include <cfloat>

vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	return result;

}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	//return lhs.x == rhs.x && lhs.y == rhs.y;
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}
}
