	
#include "polygon.h"
bool polygon::Intersect(const ray &R, intersection &inter)
{
	double Pinter = Dot(R.v,n);

	if (IsZero(Pinter))
	{
			return false;
	}


	vector x = R.p - p[0];
	double t = -Dot(x,n) / Pinter;
	if (t <= 0) 
	{
		return false;
	}


	point Pi = R.PointOnRay(t);
	for (int i = 0; i < nPoints-1; i++) 
	{
		vector R = Cross(p[i+1]-p[i],n);
		double W = Dot(Pi - p[i],R);
		if (W>0)
		{
			return false;
		}
	}
	inter.p = Pi;
	inter.n = n;
	inter.t = t;
	return true;
}

void polygon::CalculateNormal(void)
{
		int i = 0;
	do {
		vector v1 = p[i + 1] - p[0];
		vector v2 = p[i + 2] - p[0];
		n = Cross(v1, v2);
		i++;
	} while (IsZero(n.Length()) && i < nPoints -2);
	n.Normalize();
}
	