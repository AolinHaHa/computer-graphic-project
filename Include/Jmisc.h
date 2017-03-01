// jmisc.h

#ifndef __JMISC_H__
#define __JMISC_H__

#define NOMINMAX

#include <math.h>
#include <stdarg.h>
#include "jstring.h"
 
const double PI = 3.14159265358979323;

#ifndef	uint
#define uint unsigned int
#endif

bool IsWhitespace(char k);

/*
template <class Item>
Item max(const Item& x, const Item& y)
{
	return (x < y ? y : x);
}

template <class Type>
Type min(const Type &x, const Type& y)
{
	return (x < y ? x : y);
}

template <class Type>
inline void swap(Type &x, Type &y)
{
     Type tmp = y;
     y = x; x = tmp;
}
*/

template <class Type>
inline Type sqr(const Type& x)
{
	return x*x;
}

template <class Type>
inline Type sgn(const Type& x)
{
	return ((x) < 0 ? -1 : 1);
}

inline double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x2 - x1) + sqr(y2 - y1));
}

inline double dist(double *p1, double *p2)
{
	double len = 0;

	for (int i = 0; i < 3; i++)
		len += sqr(p2[i] - p1[i]);

	return sqrt(len);
}

void jMessageBox(char *message, ...);
void complain(char *str, ...);
void complain(const jstring& s);

const double TD_SMALL = 1e-6;

double ipow(double x, int k);

double ran1(void);
void sran1(long Seed);
double normalRan(void);

int Choose(int n, int i);
double Bezier(int n, int i, double x);

#endif
