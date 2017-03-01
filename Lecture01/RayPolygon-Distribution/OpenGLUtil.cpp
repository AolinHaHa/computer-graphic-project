
#include "OpenGLUtil.h"

void DrawSphere(OpenGLWin &win, const point &p, double rad, int resolution) 
{
	win.DrawSphere(p[0], p[1], p[2], rad, resolution);
}

void DrawCylinder(OpenGLWin &win, const point &base, const vector &direction, 
				  double rad, int resolution)
{
	win.DrawCylinder(base[0], base[1], base[2], direction[0], direction[1],
					 direction[2], rad, direction.Length(), resolution);
}

void DrawCone(OpenGLWin &win, const point &base, const vector &direction, 
				  double rad, int resolution) 
{
	win.DrawCone(base[0], base[1], base[2], direction[0], direction[1],
					 direction[2], rad, direction.Length(), resolution);	
}

void DrawArrow(OpenGLWin &win, const point &base, const vector &v, 
			   double rad, int resolution) 
{	
	win.DrawArrow(base[0], base[1], base[2], v[0], v[1],
					 v[2], rad, v.Length(), resolution);
}

void DrawLine(OpenGLWin &win, const point &p1, const point &p2, bool lit)
{
	double P1[3], P2[3];

	P1[0] = p1[0]; P1[1] = p1[1]; P1[2] = p1[2]; 
	P2[0] = p2[0]; P2[1] = p2[1]; P2[2] = p2[2]; 

	win.DrawLine(P1, P2, lit);
}

void DrawPolygon(OpenGLWin &win, point *p, int nPoints, bool lit)
{
	double P[100][3];

	for (int i = 0; i < nPoints; i++)
	{
		P[i][0] = p[i][0]; P[i][1] = p[i][1]; P[i][2] = p[i][2]; 
	}

	win.DrawPolygon(P, nPoints, lit);
}

