#pragma warning(disable : 4996) // Turns off secure_crt warnings in VS 2005 and up

#include "point.h"
#include <math.h>
#include <jmisc.h> // Miscellaneous routines, including sqr()

point::point(double x, double y, double z)
{
	p[0] = x;
	p[1] = y;
	p[2] = z;
	p[3] = 1.0;
}

bool IsZero(const point &p)
{
	if (fabs(p[0]) < ALMOST_ZERO&&fabs(p[1]) < ALMOST_ZERO&&fabs(p[2]) < ALMOST_ZERO) 
		return true;
	else 
		return false;
	// To Do
	//
	// Return true if the point p is the origin (0, 0, 0).
	//finished
}
void point::Normalize (void)
{
	point temp =*this;
	p[0] = p[0]/p[3];
	p[1] = p[1]/p[3];
	p[2] = p[2]/p[3];
	p[3] = p[3]/p[3];
	*this = temp;
}
bool IsNormal (const point&p)
{
	return IsEqual(p[3],1);
}
bool IsEqual(const point &p, const point &q)
{
	// To Do 
	//
	// Return true if the two points are equal
	//finished
	if (fabs(p[0] - q[0]) < ALMOST_ZERO&&fabs(p[1] - q[1]) < ALMOST_ZERO&&fabs(p[2] - q[2]) < ALMOST_ZERO)
		return true;
	else
		return false;
}

bool IsNotEqual(const point &p, const point &q) 
{ 
	return !IsEqual(p, q); 
}

double Distance(const point &p, const point &q)
{
	// To Do
	//
	// Calculate the distance between the two points
	//finished
	return sqrt(fabs(pow(p[0]-q[0],2)) + fabs(pow(p[1]-q[1],2)) + fabs(pow(p[2]-q[2],2)));
	
}

istream &operator>>(istream &input, point &p)
{
	input >> p[0] >> p[1] >> p[2];
	return input;
}

ostream &operator<<(ostream &output, const point &p)
{
	output << p[0] << " " << p[1] << " " << p[2];
	return output;
}

