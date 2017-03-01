#ifndef __OPENGLUTIL_H__
#define __OPENGLUTIL_H__

#include "point.h"
#include "vector.h"
#include <OpenGLWin.h>

void DrawSphere(OpenGLWin &win, const point &p, double rad, int resolution = 20);
void DrawCylinder(OpenGLWin &win, const point &base, const vector &direction, 
				  double rad, int resolution = 20);
void DrawCone(OpenGLWin &win, const point &base, const vector &direction, 
				  double rad, int resolution = 20);
void DrawArrow(OpenGLWin &win, const point &base, const vector &v, 
			   double rad, int resolution = 20);

void DrawLine(OpenGLWin &win, const point &p1, const point &p2, bool lit = false);
void DrawPolygon(OpenGLWin &win, point *p, int n, bool lit = true);
#endif