#ifndef __OPENGLWIN_H__
#define __OPENGLWIN_H__

#include "AppWindow.h"
#include "jmatrix.h"

#include <gl/gl.h>
#include <gl/glu.h>


class OpenGLWin : public AppWindow
{
public:
      
	OpenGLWin();
	OpenGLWin(int x, int y, int width, int height, bool Visible = true);
	OpenGLWin(Window &parent, int x, int y, int width, int height, bool Visible = true);
	virtual ~OpenGLWin();

	void OpenGLWinSetup();

	// OpenGL Utilities
	void MakeCurrent(void);
	void SwapBuffers(void);
	void Refresh(void);
	void Clear(void);

	// Transformation Methods (view setup)
	void SetCameraPos(double x, double y, double z);
	void SetCameraTarget(double x, double y, double z);
	void SetCameraUp(double x, double y, double z);
	void SetCameraFov(double Fov);
	void SetCameraDepth(double Near, double Far);
	void SetCamera(double CamX, double CamY, double CamZ, 
				   double TargX, double TargY, double TargZ,
				   double UpX, double UpY, double UpZ,
				   double Fov, double Near, double Far);
	void SetupCamera(void);
	void Setup2DView(double xll, double yll, double xur, double yur);

	// Coordinate system conversion (for on-screen selection)
	void WorldToScreen(double objX, double objY, double objZ, double win[3]);
	void ScreenToWorld(double winX, double winY, double winZ, double obj[3]);
	void ScreenToWorld2D(double winX, double winY, double obj[3]);

	// World Setup Methods
	void SetupDistantLight(double posX, double posY, double posZ, 
						  double difR = -1, double difG = -1, double difB = -1, double difA = -1,
						  double ambR = -1, double ambG = -1, double ambB = -1, double ambA = -1,
						  double spcR = -1, double spcG = -1, double spcB = -1, double spcA = -1);
	void SetMaterial(double ambR, double ambG, double ambB, double ambA = 1,
					double difR = -1, double difG = -1, double difB = -1, double difA = 1,
					double spcR = -1, double spcG = -1, double spcB = -1, double spcA = 1,
					double shininess = -1);
	void SetColor(double r, double g, double b, double a = 1);
	void SetSpecular(double spcR, double spcG, double spcB, double shininess = 10);

	// Methods to Save an Image
	void Save(char *filename, bool Compressed = false);

	// Simple Shape Methods
	void DrawSphere(double cx, double cy, double cz, double rad, int resolution);
	void DrawCylinder(double bx, double by, double bz, 
		 			  double vx, double vy, double vz,
					  double rad, double len, int resolution);
	void DrawCone(double bx, double by, double bz, 
				  double vx, double vy, double vz,
				  double rad, double len, int resolution);
	void DrawArrow(double bx, double by, double bz, 
				   double vx, double vy, double vz,
				   double rad, double len, int resolution);
	void DrawLine(const double *p1, const double *p2, bool lit);
	void DrawPolygon(const double p[][3], int nPoints, bool lit = true);
	void DrawTeapot(double x, double y, double z, double size, int resolution = 20, bool yUp = false);
	void CalculateBilinearInterp(double result[3], double normal[3], double v00[3], double v01[3], double v10[3], double v11[3], double u, double v, bool calcNormal);
	void CalculateBezierPoint(double result[3], double normal[3], double vertices[][3], int indices[16], double u, double v);
	void DrawBezierPatch(double vertices[][3], int indices[16], int resolution, double scaleX = 1.0, double scaleY = 1.0, double scaleZ = 1.0, double nScaleX = 1.0, double nScaleY = 1.0, double nScaleZ = 1.0);


private:

	HGLRC OpenGLRC;
	static HGLRC CurrentRC;
	bool OpenGLActive;

    double ViewDist;
    double camX, camY, camZ;
    double targX, targY, targZ;
    double upX, upY, upZ;
	double fov, nearZ, farZ;

	// Utility Methods
	void Destroy3D(void);
	void SetupPixelFormat(void);
	void Setup3DGraphics(void);

	GLuint teapotList[100];

	int GetScreenBitDepth(void);
	LONG ProcessMessage(HWND hWnd, size_t msg, size_t wParam, LONG lParam);
};


#endif 
