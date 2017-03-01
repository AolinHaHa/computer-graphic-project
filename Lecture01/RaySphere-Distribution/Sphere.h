#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "point.h"
#include "vector.h"
#include "Shape.h"

class sphere : public shape
{
public:

	// Intersects the ray returning by reference the "t" value
	// and also the position and normal of the intersection.
	// It returns a bool indicating whether there is an 
	// Intersection or not.
	bool Intersect(const ray &R, intersection &I);

	point center;
	double radius;
};

#endif