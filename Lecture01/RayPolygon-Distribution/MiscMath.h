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
	// Check to see if they are close using an absolute epsilon
	if (fabs(x - y) < ALMOST_ZERO)
		return true;
	
	// If not, check if they are relatively close, note ... requires division
	double denom = (x > y ? x : y);	  // Denom = max(x, y)
	double relErr = fabs((x - y) / denom);

	return (relErr < ALMOST_ZERO);
}

inline bool IsNotEqual(double x, double y)
{
	return !IsEqual(x, y);
}

#endif