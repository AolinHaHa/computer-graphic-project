#ifndef __QUAT_H__
#define __QUAT_H__

#include <assert.h>
#include <iostream>
using namespace std;

#include "vector.h"
#include "jmisc.h"
#include "Matrix.h"

class quat
{
public:

	quat() : w(1.0), v(0.0, 0.0, 0.0) { }
	quat(double W, double X = 0.0, double Y = 0.0, double Z = 0.0) : w(W), v(X, Y, Z) { }
	quat(double W, vector V) : w(W), v(V) { }

	double &operator[](int i) { assert(i >= 0 && i <= 3); if (i == 0) return w; else return v[i - 1]; }
	double operator[](int i) const { assert(i >= 0 && i <= 3); if (i == 0) return w; else return v[i - 1]; }

	double Length() const;
	void Normalize();

	quat conj(void) const;
	quat inverse(void) const;

	double scale(void) const;

	quat &operator+=(const quat &r);
	quat &operator-=(const quat &r);
	quat &operator*=(const quat &r);
	quat &operator/=(const quat &r);

	vector rotate(vector v) const;

	void QuatFromAngleAxis(double a[4]);
	void QuatFromAngleAxis(double theta, vector V);
	void QuatToAngleAxis(double a[4]) const;
	void QuatToAngleAxis(double &theta, vector &V) const;
	void QuatFromEulerAngles(double x, double y, double z);

	double w;
	vector v;
};

quat operator-(const quat &q);
quat operator+(const quat &q1, const quat &q2);
quat operator-(const quat &q1, const quat &q2);
quat operator*(const quat &q1, const quat &q2);
quat operator/(const quat &q1, const quat &q2);
double dot(const quat &a, const quat &b);
ostream &operator<<(ostream &output, const quat &q);

#endif