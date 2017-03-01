#pragma warning(disable : 4996) // Turns off secure_crt warnings in VS 2005 and up

#include <math.h>
#include <jmisc.h> // Miscellaneous routines, including sqr()
#include "vector.h"


////////////////////////////////////////////////////////////////////////////
// Methods of the vector class
////////////////////////////////////////////////////////////////////////////

vector::vector(double x, double y, double z)
{
	v[0] = x; 
	v[1] = y; 
	v[2] = z;
	v[3] = 0.0;
}

double vector::Length(void) const 
{
	// To Do
	//
	// Return the length of this vector;
	//finished
	double len = sqrt(pow(v[0],2)+pow(v[1],2));
	return (len);
	
}

void vector::Normalize(void)
{
	// To Do
	//
	// Normalize this vector, but make sure to check whether the vector is zero or not
	// Check if it is the zero vector.
	//finished
	if (IsNotZero(vector::Length()))
	{
		
			double x =v [0]/vector::Length();
			double y =v [1]/vector::Length();
			double z =v [2]/vector::Length();
			v[0] = x;
			v[1] = y;
			v[2] = z;
		}
		


}

vector &vector::operator+=(const vector &w)
{
	// To Do 
	//
	// Add the vector "w" to this vector.  Note that we have to return this vector once we
	// are done to support c++ statement such as v0 = v1 = v2.
	//finished
	v[0] = v[0] + w[0];
	v[1] = v[1] + w[1];
	v[2] = v[2] + w[2];
	return vector(v[0], v[1], v[2]);
	
}

vector &vector::operator-=(const vector &w)
{
	// To Do 
	//
	// Subtract the vector "w" from this vector.
	//finished
	v[0] = v[0] - w[0];
	v[1] = v[1] - w[1];
	v[2] = v[2] - w[2];
	return vector(v[0], v[1], v[2]);
}

vector &vector::operator*=(double d)
{
	// To Do 
	//
	// Multiply this vector by the scalar d.
	//finished
	v[0] = v[0] * d;
	v[1] = v[1] * d;
	v[2] = v[2] * d;
	return vector(v[0], v[1], v[2]);

}

vector &vector::operator/=(double d)
{
	// To Do 
	//
	// Divide this vector by the scalar d, make sure to check to see if it can be done 
	//finished
	//if(IsNotZero(d))
	//{
		v[0] = v[0] / d;
		v[1] = v[1] / d;
		v[2] = v[2] / d;
		return vector(v[0], v[1], v[2]);
	//}
//	else
	//	cout<<"cant divide by 0"<< endl;
}

// Calculates the projection of v onto w
vector vector::Proj(const vector &w)
{
	// To Do
	//
	// Calculate the projection of "this" vector onto the vector w
	vector x;
	if (!(IsZero(w[0])&&IsZero(w[1])&&IsZero(w[2])))
	{
		x = w * ((v[0]*w[0]+v[1]*w[1]+v[2]*w[2])/(w[0]*w[0]+w[1]*w[1]+w[2]*w[2]));
	}

	return x;
}

vector vector::Perp(const vector &w)
{
	// To Do
	//
	// Calculate the projection of "this" vector perpendicular to the vector w
	vector x;
	vector y= * this;
	x= y-y.Proj(w);
	return x;
}

bool IsZero(const vector &v)
{
	// To Do
	//
	// Return true if the vector is a zero vector, otherwise return false
	//finished
	if (fabs(v[0]) < ALMOST_ZERO&&fabs(v[1]) < ALMOST_ZERO&&fabs(v[2]) < ALMOST_ZERO)
		return true;
	else
		return false;
}

bool IsEqual(const vector &v, const vector &w)
{
	// To Do
	//
	// Return true if the two vectors are equal, otherwise return false
	//finished
	//if (fabs(v[0] - w[0]) < ALMOST_ZERO&&fabs(v[1] - w[1]) < ALMOST_ZERO&&fabs(v[2] - w[2]) < ALMOST_ZERO)
		//return true;
	//else
	if(IsEqual(v[0],w[0]), IsEqual(v[1],w[1]), IsEqual(v[2],w[2])){
	return true;
	}
		return false;
}

bool IsNotEqual(const vector &v, const vector &w)
{ 
	return !IsEqual(v, w); 
}

double Dot(const vector &v, const vector &w)
{
	// To Do
	//
	// Return the dot product of v and w
	//finished
	return (v[0]*w[0]+v[1]*w[1]+v[2]*w[2]);
}

vector Cross(const vector &v, const vector &w)
{
	// To Do
	//
	// Return the vector cross product of v and w
	double x = v[1]*w[2]-v[2]*w[1];
	double y = v[2]*w[0]-v[0]*w[2];
	double z = v[0]*w[1]-v[1]*w[0];
	return vector(x,y,z);
}

vector operator+(const vector &v, const vector &w)
{
	// To Do
	//
	// Return the sum of v and w
	//finished
	return vector(v[0]+w[0], v[1]+w[1], v[2]+w[2]);
}

vector operator-(const vector &v, const vector &w)
{
	// To Do
	//
	// Return the difference of v and w
	//finished
	return vector(v[0]-w[0], v[1]-w[1], v[2]-w[2]);
}

vector operator*(double d, const vector &v)
{
	// To Do
	//
	// Return the product of d and v
	//finished
	return vector(v[0]*d, v[1]*d, v[2]*d);
}

vector operator*(const vector &v, double d)
{
	return d * v;
}

vector operator/(const vector &v, double d)
{
	// To Do
	//
	// Return the quotient of v and d.  Don't forget to check if d is zero.
	//finished
	//if (IsNotZero(d))
	//{
		return vector(v[0]/d, v[1]/d, v[2]/d);
	//}
	//else
		//cout<<"cant divide by 0"<< endl;
}

point operator+(const point &p, const vector &v)
{
	// To Do
	// 
	// Return the sum of p and v
	//finished
	return point(p[0]+v[0], p[1]+v[1],p[2]+v[2]);
}

// Note that this one really doesn't make sense geometrically, 
// but sometimes we define certain operators for symmetry and 
// for ease of programming.  But you should be careful to see
// what the operation means when you do it.
point operator+(const vector &v, const point &p)
{
	assert (!(IsNormal(p)));
	return p + v;
}

point &operator+=(point &p, const vector &v)
{
	// To Do
	//
	// Add v to the point p and then return it
	assert (!(IsNormal(p)));
	p[0] = p[0] + v[0];
	p[1] = p[1] + v[1];
	p[2] = p[2] + v[2];
	return point(p[0],p[1],p[2]);
}

point operator-(const point &p, const vector &v)
{
	// To Do
	// 
	// Return p - v
	//finished
	assert (!(IsNormal(p)));
	return point(p[0]-v[0], p[1]-v[1],p[2]-v[2]);
}

point &operator-=(point &p, const vector &v)
{
	// To Do
	//
	// Subtract the vector v from p, and return p.
	assert (!(IsNormal(p)));
	p[0] = p[0] - v[0];
	p[1] = p[1] - v[1];
	p[2] = p[2] - v[2];
	return point(p[0],p[1],p[2]);
}

vector operator-(const point &p, const point &q)
{
	// To Do
	//
	// Subtract the two points, p and q
	//finished
	return vector(p[0]-q[0], p[1]-q[1],p[2]-q[2]);
}

vector operator-(const vector &v)
{
	// To Do
	//
	// Return the negative of v
	//finished
	return vector(-v[0], -v[1], -v[2]);
}

istream &operator>>(istream &input, vector &v)
{
	input >> v[0] >> v[1] >> v[2];
	return input;
}

ostream &operator<<(ostream &output, const vector &v)
{
	output << v[0] << " " << v[1] << " " << v[2];
	return output;
}
