#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "point.h"
#include "vector.h"
#include "ray.h"

struct intersection
{
 double t;   // Value of t on the ray at which the intersection occurred
 point p;   // Position of the intersection
 vector n;   // Normal of the surface at the intersection point
};

class shape
{
public:

	shape();

	virtual bool Intersect(const ray &R, intersection &I) = 0;

protected:

};

#endif