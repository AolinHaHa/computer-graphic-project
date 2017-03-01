// For the Foruth example, we add a Label control to the 
// bottom of the window which displays the position of the
// Sphere

#include "win.h"
#include "point.h"
#include "matrix.h"
#include "OpenGLUtil.h"

class Application : public EventListener
{
public:

	Application();

private:

	AppWindow	Win;
	OpenGLWin	Win3D;
	
	// Controls
	Label		lblAngleX;
	ScrollBar	scrAngleX;
	Label		lblAngleY;
	ScrollBar	scrAngleY;
	Label		lblAngleZ;
	ScrollBar	scrAngleZ;
	Label		lblTrans;
	ScrollBar	scrTransX;
	ScrollBar	scrTransY;
	ScrollBar	scrTransZ;
	Label		lblScaleX;
	ScrollBar	scrScaleX;
	Label		lblScaleY;
	ScrollBar	scrScaleY;
	Label		lblScaleZ;
	ScrollBar	scrScaleZ;

	// Data
	point p[6]; // Our polygon will have six sides
	point q[6]; // To hold the rotated points
	matrix m;
	int selectedPoint;

	// Methods
	void SetupControls(void);

	// Event Handlers
	void UpdateWindow(intRect UpdateRect);
	void DrawScene(void);
	void ResizeMainWindow(size_t w, size_t h);
	void Resize3DWindow(size_t w, size_t h);
	void ScrollAngle(int pos);
};

Application::Application() : Win(0, 0, 800, 400), Win3D(Win, 0, 0, 400, 400)
{ 
	Win.SetText("Manipulating a Polygon");

	Win.AddMainMenu();
	Win.AddFileMenu();
	Win.SetSizeEvent(this, &Application::ResizeMainWindow);

	Win3D.SetPaintEvent(this, &Application::UpdateWindow);
	Win3D.SetSizeEvent(this, &Application::Resize3DWindow);

	for (int i = 0; i < 6; i++)
	{
		p[i][0] = .5 * cos(i * PI / 3);
		p[i][1] = .5 * sin(i * PI / 3);
		p[i][2] = 0.0;
	}

	// The following commands set up a veiw of the three principal axes.
	// The view's camera is set to a position of (3, 3, 3) pointing at
	// the origin (0, 0, 0) and with the top of the camera pointing 
	// "up" = <0, 0, 1> the z-axis
	Win3D.SetCameraPos(3, 2, 2);
	Win3D.SetCameraTarget(0, 0, 0);
	Win3D.SetCameraUp(0, 0, 1);

	// These are all the default light attributes, except for the specular
	// I.e. this is how to turn off specular reflectance.  We will see more
	// about lighting later.
	Win3D.SetupDistantLight(1.0, 1.0, 1.0,      // Position
			                1.0, 1.0, 1.0, 1.0, // Diffuse
				  		    0.2, 0.2, 0.2, 1.0, // Ambient
						    0.0, 0.0, 0.0, 1.0);// Specular
	selectedPoint = -1;
	SetupControls();

	m = matrix::Identity(4);
}

void Application::SetupControls(void)
{
	lblAngleX.Setup(Win, 410, 10, 380, 20, "Angle of Rotation = 0.0 about the x-axis", Label::Left);
	scrAngleX.Setup(Win, 410, 30, 380, 20, 0, 3600, 0, 360);
	scrAngleX.SetScrollEvent(this, &Application::ScrollAngle);
	lblAngleY.Setup(Win, 410, 55, 380, 20, "Angle of Rotation = 0.0 about the y-axis", Label::Left);
	scrAngleY.Setup(Win, 410, 75, 380, 20, 0, 3600, 0, 360);
	scrAngleY.SetScrollEvent(this, &Application::ScrollAngle);
	lblAngleZ.Setup(Win, 410, 100, 380, 20, "Angle of Rotation = 0.0 about the z-axis", Label::Left);
	scrAngleZ.Setup(Win, 410, 120, 380, 20, 0, 3600, 0, 360);
	scrAngleZ.SetScrollEvent(this, &Application::ScrollAngle);

	lblTrans.Setup(Win, 410, 150, 380, 20, "Translation of (0.0, 0.0, 0.0)", Label::Left);
	scrTransX.Setup(Win, 410, 170, 380, 20, 0, 2000, 1000, 200);
	scrTransX.SetScrollEvent(this, &Application::ScrollAngle);
	scrTransY.Setup(Win, 410, 200, 380, 20, 0, 2000, 1000, 200);
	scrTransY.SetScrollEvent(this, &Application::ScrollAngle);
	scrTransZ.Setup(Win, 410, 230, 380, 20, 0, 2000, 1000, 200);
	scrTransZ.SetScrollEvent(this, &Application::ScrollAngle);

	lblScaleX.Setup(Win, 410, 260, 380, 20, "Scale by 1.00 in X", Label::Left);
	scrScaleX.Setup(Win, 410, 280, 380, 20, 0, 4000, 3000, 400);
	scrScaleX.SetScrollEvent(this, &Application::ScrollAngle);
	lblScaleY.Setup(Win, 410, 305, 380, 20, "Scale by 1.00 in Y", Label::Left);
	scrScaleY.Setup(Win, 410, 325, 380, 20, 0, 4000, 3000, 400);
	scrScaleY.SetScrollEvent(this, &Application::ScrollAngle);
	lblScaleZ.Setup(Win, 410, 350, 380, 20, "Scale by 1.00 in Z", Label::Left);
	scrScaleZ.Setup(Win, 410, 370, 380, 20, 0, 4000, 3000, 400);
	scrScaleZ.SetScrollEvent(this, &Application::ScrollAngle);
}

void Application::UpdateWindow(intRect UpdateRect)
{
	DrawScene();
}

void Application::DrawScene(void)
{
	point center;
	int i;

	Win3D.Clear();
	glEnable(GL_LIGHTING);

	// The command for drawing an arrow takes a starting point,
	// and the vector to draw, as well as a radius for the arrow's
	// shaft
	Win3D.SetColor(1.0, 0.0, 0.0);
	DrawArrow(Win3D, point(0, 0, 0), vector(1, 0, 0), .01);
	Win3D.SetColor(0.0, 1.0, 0.0);
	DrawArrow(Win3D, point(0, 0, 0), vector(0, 1, 0), .01);
	Win3D.SetColor(0.0, 0.0, 1.0);
	DrawArrow(Win3D, point(0, 0, 0), vector(0, 0, 1), .01);

	for (i = 0; i < 6; i++)
	{
		if (i % 3 == 0)
			Win3D.SetColor(1.0, 0.0, 0.0);
		else
			Win3D.SetColor(1.0, 1.0, 0.0);
		q[i] = m * p[i];
		DrawSphere(Win3D, q[i], .02, 20);
		center = m * point(0, 0, 0);
		DrawSphere(Win3D, center, .02, 20);
	}

	glLineWidth(2);
	for (i = 0; i < 6; i++)
		DrawLine(Win3D, q[i], q[(i+1) % 6], false);

	// Draw Polygon simply takes an array of points and the
	// number of points in the array.  The points are assumed to
	// be in counter clockwise order ... but more on that later.
	Win3D.SetColor(.4, .2, 0.0);
	DrawPolygon(Win3D, q, 6);

	Win3D.SwapBuffers();
}

void Application::ResizeMainWindow(size_t w, size_t h)
{
	Win3D.Resize(w, h);
}

void Application::Resize3DWindow(size_t w, size_t h)
{
	Win3D.SetCameraPos(5, 5, 5);
	Win3D.SetCameraTarget(0, 0, 0);
	Win3D.SetCameraUp(0, 0, 1);
}

void Application::ScrollAngle(int pos)
{
	matrix mX, mY, mZ, T, S;

	lblAngleX.SetText("Angle of Rotation = %0.2lf about the x-axis", scrAngleX.Value() / 10.0);
	lblAngleY.SetText("Angle of Rotation = %0.2lf about the y-axis", scrAngleY.Value() / 10.0);
	lblAngleZ.SetText("Angle of Rotation = %0.2lf about the z-axis", scrAngleZ.Value() / 10.0);
	lblTrans.SetText("Translation of (%0.2lf, %0.2lf, %0.2lf)",
		              scrTransX.Value() / 1000.0 - 1, scrTransY.Value() / 1000.0 - 1, scrTransZ.Value() / 1000.0 - 1);
	lblScaleX.SetText("Scale by %0.2lf in X", scrScaleX.Value() / 1000.0 - 2);
	lblScaleY.SetText("Scale by %0.2lf in Y", scrScaleY.Value() / 1000.0 - 2);
	lblScaleZ.SetText("Scale by %0.2lf in Z", scrScaleZ.Value() / 1000.0 - 2);

	mX.MakeRotationX(scrAngleX.Value() / 10.0);
	mY.MakeRotationY(scrAngleY.Value() / 10.0);
	mZ.MakeRotationZ(scrAngleZ.Value() / 10.0);
	T.MakeTranslation(scrTransX.Value() / 1000.0 - 1, scrTransY.Value() / 1000.0 - 1, scrTransZ.Value() / 1000.0 - 1);
	S.MakeScale(scrScaleX.Value() / 1000.0 - 2, scrScaleY.Value() / 1000.0 - 2, scrScaleY.Value() / 1000.0 - 2);
	m = T * mZ * mY * mX * S;

	m.Print();
	cout << endl;

	DrawScene();
}

void main()
{
	Application app;

	EventLoop();
}

