
#include "quat.h"

double quat::Length() const
{
	// To Do
	//
	// Calculate the length of the quaternion
	double x =sqr(w)+sqr(v[0]) + sqr(v[1]) + sqr(v[2]);
	return sqrt(x); 
}

void quat::Normalize()
{
	double l = Length();
	assert(IsNotZero(l));
	w /= l;
	v[0] /= l;
	v[1] /= l;
	v[2] /= l;
	// To Do
	//
	// Normalize the quaternion
}

quat quat::conj(void) const
{
	// To Do
	return quat(w, -v[0], -v[1], -v[2]);
	// return the conjugate of this quat

}

quat quat::inverse(void) const
{
	// To Do
	//
	// Return the inverse of this quat
	quat cn = conj();
	double sl = sqr(Length());
	assert(sl);
	cn.w /= sl;
	cn.v[0] /= sl;
	cn.v[1] /= sl;
	cn.v[2] /= sl;
	return cn;
	
}

double quat::scale(void) const
{
	return Length();
}

quat &quat::operator+=(const quat &r)
{
	// To Do
	//
	// Add the quat "r" to this quat
	w+=r.w;
	v+=r.v;
	return *this;
}

quat &quat::operator-=(const quat &r)
{
	// To Do
	//
	// Subtract the quat "r" from this quat
	
	w -= r.w;
	v -= r.v;
	return *this;
}

quat &quat::operator*=(const quat &r)
{
	// To Do
	//
	// Multiply this quat by "r" on the right
	w = (w*r.w) - Dot(v,r.v);
	v = (r.w*v)+(w*r.v)+Cross(v,r.v);
	return *this;
}

quat &quat::operator/=(const quat &r)
{
	// To Do
	//
	// Divide this quat by the quat "r"
	quat x(r);
	x.inverse();
	return *this*x;
}

vector quat::rotate(vector v) const
{
	// To Do
	//
	// Calculate the rotation of the vector "v" by this quat
	// Make sure that when you are done, the result quaternion has a w = 0, and then
	// return it's vector part.
	quat anew(0,v);
	quat makeconj(*this);
	makeconj.conj();
	return (*this *anew*makeconj).v;

}

void quat::QuatFromAngleAxis(double a[4])
{
	// To Do
	//
	// Convert the angle axis value stored in the array to a quat.
	// The array contains (angle, ax, ay, az).  Note that "a" may not
	// be normalized!
	double sindiv = sin(a[0]/2);
	w = cos(a[0]/2);
	v[0] = sindiv*a[1];
	v[1] = sindiv*a[2];
	v[2] = sindiv*a[3];
}

void quat::QuatFromAngleAxis(double theta, vector V)
{
	// To Do
	//
	// Same as above but with a different type of angle axis storage
	double sindiv = sin(theta/2);
	w = cos(theta/2);
	v[0] = sindiv*v[0];
	v[1] = sindiv*v[1];
	v[2] = sindiv*v[2];
}

void quat::QuatToAngleAxis(double a[4]) const
{
	// To Do
	//
	// Do the opposite of the above operation


}

void quat::QuatToAngleAxis(double &theta, vector &V) const
{
	// To Do
	//
	// Once again, but convert it to an angle and an axis vector
}

void quat::QuatFromEulerAngles(double x, double y, double z)
{
	// To Do
	//
	// Convert the given euler angles to a quat
}

quat operator-(const quat &q)
{
	// To Do
	//
	// Return the negative of this quat
	double a = -q.w;
	double b = -q.v[0];
	double c = -q.v[1];
	double d = -q.v[2];
	return quat(a, b ,c , d);
}

quat operator+(const quat &q1, const quat &q2)
{
	// To Do
	//
	// Return the sum of these two quats
	double a = q1.w + q2.w;
	double b = q1.v[0] + q2.v[0];
	double c = q1.v[1] + q2.v[1];
	double d = q1.v[2] + q2.v[2];
	return quat(a,b,c,d);
}

quat operator-(const quat &q1, const quat &q2)
{
	// To Do
	//
	// Return the difference of these two quats
	double a = q1.w - q2.w;
	double b = q1.v[0] - q2.v[0];
	double c =  q1.v[1] - q2.v[1];
	double d = q1.v[2] - q2.v[2];
	return quat(a,b,c,d);
}

quat operator*(const quat &q1, const quat &q2)
{
	// To Do
	//
	// Return the product of these two quats
	double w0w1= q1.w * q2.w;
	double vdot = Dot(q1.v, q2.v);
	double ww = w0w1-vdot;
	vector vcros = Cross(q1.v, q2.v);
	vector temp = (q2.w *q1.v) + (q1.w * q2.v) + vcros;
	return quat(ww,temp[0],temp[1],temp[2]);

}

quat operator/(const quat &q1, const quat &q2)
{
	// To Do
	//
	// Return the quat of these two quats
	quat newq(q2);
	newq.inverse();
	return q1 * newq;
}

double dot(const quat &a, const quat &b)
{
	// To Do
	//
	// Return the dot product of these two quats
	double w = a.w*b.w;
	double x = a.v[0]*b.v[0];
	double y = a.v[1]*b.v[1];
	double z = a.v[2]*b.v[2];
	return w+x+y+z;
}

ostream &operator<<(ostream &output, const quat &q)
{
	output << "(" << q.w << ", <" << q.v[0] << ", " << q.v[1] << ", " << q.v[2] << ">)";
	return output;
}

