#ifndef __MISCMATH_H__
#define __MISCMATH_H__

const double ALMOST_ZERO = 1e-10;

inline bool IsZero(double x)
{
	return (fabs(x) < ALMOST_ZERO);
}

inline bool IsNotZero(double x)
{
	return !IsZero(x);
}

inline bool IsEqual(double x, double y)
{
	return (fabs(x - y) < ALMOST_ZERO);
}

inline bool IsNotEqual(double x, double y)
{
	return !IsEqual(x, y);
}

#endif