
#include "jmisc.h"
#include "sphere.h"

// Returns a boolean indicating whether the ray intersects
// The sphere, if it does then it the members of "inter" with
// the intersection data.  It fills t with the closest
// intersection "time", t > 0 and fills p and n with the 
// position and normal of the intersection.

bool sphere::Intersect(const ray &R, intersection &inter)
{
	double t1, t2;
	double a, b, c;

	vector Q = (R.p - center);
	
	a = Dot(R.v, R.v); 
	b = 2.0 * Dot(R.v, Q);
	c = Dot(Q, Q) - sqr(radius);

	double discriminant = sqr(b) - 4*a*c;
	if (discriminant >= 0)
	{
		double sqrtDiscriminant = sqrt(discriminant);
		t1 = (-b + sqrtDiscriminant) / (2.0 * a);
		t2 = (-b - sqrtDiscriminant) / (2.0 * a);

		if ((t1 < 0.0) || (t2 < 0.0))
		{
			if ((t1 < 0.0) && (t2 < 0.0))
				return false;	
			else if (t1 > 0)
				inter.t = t1;
			else
				inter.t = t2;
		}
		else
			inter.t = min(t1, t2);

		inter.p = R.PointOnRay(inter.t);
		inter.n = inter.p - center;
		inter.n.Normalize();
		return true;
	}
	else
		return false;
}

