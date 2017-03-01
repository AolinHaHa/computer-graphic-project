// For the Foruth example, we add a Label control to the 
// bottom of the window which displays the position of the
// Sphere

#include "win.h"
#include "point.h"
#include "ray.h"
#include "sphere.h"
#include "OpenGLUtil.h"

class Application : public EventListener
{
public:

	Application();

private:

	AppWindow	Win;
	OpenGLWin	Win3D;
	
	// Controls
	Button		ControlBox;

	Button		SphereBox;
	Label		SPosXLabel;
	Label		SPosYLabel;
	Label		SPosZLabel;
	Label		RadiusLabel;
	ScrollBar	SPosXScroll;
	ScrollBar	SPosYScroll;
	ScrollBar	SPosZScroll;
	ScrollBar	RadiusScroll;

	Button		RayBox;
	Label		PosXLabel;
	Label		PosYLabel;
	Label		PosZLabel;
	Label		VecXLabel;
	Label		VecYLabel;
	Label		VecZLabel;
	ScrollBar	PosXScroll;
	ScrollBar	PosYScroll;
	ScrollBar	PosZScroll;
	ScrollBar	VecXScroll;
	ScrollBar	VecYScroll;
	ScrollBar	VecZScroll;

	// Data
	ray R;
	sphere S;

	// Methods
	void SetupControls(void);

	// Event Handlers
	void UpdateWindow(intRect UpdateRect);
	void DrawScene(void);
	void ResizeMainWindow(size_t w, size_t h);
	void Resize3DWindow(size_t w, size_t h);
	void SphereScrollChanged(int pos) { DrawScene(); }
	void RayScrollChanged(int pos) { DrawScene(); }
};

Application::Application() : Win(0, 0, 630, 430, false), Win3D(Win, 0, 0, 430, 430)
{ 
	Win.SetText("Intersecting a Sphere");

	Win.AddMainMenu();
	Win.AddFileMenu();
	Win.SetSizeEvent(this, &Application::ResizeMainWindow);

	Win3D.SetPaintEvent(this, &Application::UpdateWindow);
	Win3D.SetSizeEvent(this, &Application::Resize3DWindow);

	// The following commands set up a veiw of the three principal axes.
	// The view's camera is set to a position of (3, 3, 3) pointing at
	// the origin (0, 0, 0) and with the top of the camera pointing 
	// "up" = <0, 0, 1> the z-axis
	Win3D.SetCameraPos(15, 10, 10);
	Win3D.SetCameraTarget(0, 0, 0);
	Win3D.SetCameraUp(0, 0, 1);

	R.p = point(5, 0, 0);
	R.v = vector(-1, 0, 0);

	S.center = point(0, 0, 0);
	S.radius = 1.0;

	SetupControls();
	Win.Show();
}

void Application::SetupControls(void)
{
	// Note that in windows a control box is really nothing more than
	// a special type of button

	SphereBox.Setup(Win, 435, 10, 180, 160, "Sphere's Data", Button::GroupBox);

	SPosXLabel.Setup(SphereBox, 10, 20, 150, 20, "Sphere Position X");
	SPosXScroll.Setup(SphereBox, 10, 35, SphereBox.Width() - 20, 15, 0, 1000, 500, 100);
	SPosXScroll.SetChangeEvent(this, &Application::SphereScrollChanged);
	SPosXScroll.SetScrollEvent(this, &Application::SphereScrollChanged);

	SPosYLabel.Setup(SphereBox, 10, 55, 150, 20, "Sphere Position Y");
	SPosYScroll.Setup(SphereBox, 10, 70, SphereBox.Width() - 20, 15, 0, 1000, 500, 100);
	SPosYScroll.SetChangeEvent(this, &Application::SphereScrollChanged);
	SPosYScroll.SetScrollEvent(this, &Application::SphereScrollChanged);

	SPosZLabel.Setup(SphereBox, 10, 90, 150, 20, "Sphere Position Z");
	SPosZScroll.Setup(SphereBox, 10, 105, SphereBox.Width() - 20, 15, 0, 1000, 500, 100);
	SPosZScroll.SetChangeEvent(this, &Application::SphereScrollChanged);
	SPosZScroll.SetScrollEvent(this, &Application::SphereScrollChanged);

	RadiusLabel.Setup(SphereBox, 10, 125, 150, 20, "Sphere Radius");
	RadiusScroll.Setup(SphereBox, 10, 140, SphereBox.Width() - 20, 15, 0, 1000, 100, 100);
	RadiusScroll.SetChangeEvent(this, &Application::SphereScrollChanged);
	RadiusScroll.SetScrollEvent(this, &Application::SphereScrollChanged);

	RayBox.Setup(Win, 435, 185, 180, 230, "Ray's Data", Button::GroupBox);
	PosXLabel.Setup(RayBox, 10, 20, 150, 20, "Position X");
	PosXScroll.Setup(RayBox, 10, 35, RayBox.Width() - 20, 15, 0, 1000, 1000, 100);
	PosXScroll.SetChangeEvent(this, &Application::RayScrollChanged);
	PosXScroll.SetScrollEvent(this, &Application::RayScrollChanged);

	PosYLabel.Setup(RayBox, 10, 55, 150, 20, "Position Y");
	PosYScroll.Setup(RayBox, 10, 70, RayBox.Width() - 20, 15, 0, 1000, 500, 100);
	PosYScroll.SetChangeEvent(this, &Application::RayScrollChanged);
	PosYScroll.SetScrollEvent(this, &Application::RayScrollChanged);

	PosZLabel.Setup(RayBox, 10, 90, 150, 20, "Position Z");
	PosZScroll.Setup(RayBox, 10, 105, RayBox.Width() - 20, 15, 0, 1000, 500, 100);
	PosZScroll.SetChangeEvent(this, &Application::RayScrollChanged);
	PosZScroll.SetScrollEvent(this, &Application::RayScrollChanged);	

	VecXLabel.Setup(RayBox, 10, 125, 150, 20, "Vector X");
	VecXScroll.Setup(RayBox, 10, 140, RayBox.Width() - 20, 15, 0, 1000, 0, 100);
	VecXScroll.SetChangeEvent(this, &Application::RayScrollChanged);
	VecXScroll.SetScrollEvent(this, &Application::RayScrollChanged);

	VecYLabel.Setup(RayBox, 10, 160, 150, 20, "Vector Y");
	VecYScroll.Setup(RayBox, 10, 175, RayBox.Width() - 20, 15, 0, 1000, 500, 100);
	VecYScroll.SetChangeEvent(this, &Application::RayScrollChanged);
	VecYScroll.SetScrollEvent(this, &Application::RayScrollChanged);

	VecZLabel.Setup(RayBox, 10, 195, 150, 20, "Vector Z");
	VecZScroll.Setup(RayBox, 10, 210, RayBox.Width() - 20, 15, 0, 1000, 500, 100);
	VecZScroll.SetChangeEvent(this, &Application::RayScrollChanged);
	VecZScroll.SetScrollEvent(this, &Application::RayScrollChanged);	
}

void Application::UpdateWindow(intRect UpdateRect)
{
	DrawScene();
}

void Application::DrawScene(void)
{
	glClearColor(.85f, .85f, .85f, 1.0f);
	Win3D.Clear();

	intersection i;

	R.p[0] = 10 * PosXScroll.Pos() / 1000.0 - 5;
	R.p[1] = 10 * PosYScroll.Pos() / 1000.0 - 5;
	R.p[2] = 10 * PosZScroll.Pos() / 1000.0 - 5;

	R.v[0] = 5 * VecXScroll.Pos() / 1000.0 - 2.5;
	R.v[1] = 5 * VecYScroll.Pos() / 1000.0 - 2.5;
	R.v[2] = 5 * VecZScroll.Pos() / 1000.0 - 2.5;

	S.center[0] = 10 * SPosXScroll.Pos() / 1000.0 - 6;
	S.center[1] = 10 * SPosYScroll.Pos() / 1000.0 - 5;
	S.center[2] = 10 * SPosZScroll.Pos() / 1000.0 - 5;
	S.radius = 5 * RadiusScroll.Pos() / 1000.0 + 1;
	
	Win3D.SetColor(0.0, .6, 0.0);
	DrawSphere(Win3D, R.p, .08);
	DrawLine(Win3D, R.p, R.p + 1000 * R.v);
	DrawArrow(Win3D, R.p, 1.2 * R.v / R.v.Length(), .05);

	Win3D.SetColor(0.0, 0.0, 1.0);
	DrawSphere(Win3D, S.center, S.radius, 40);

	if (S.Intersect(R, i))
	{
		Win3D.SetColor(1.0, 0.0, 0.0);
		DrawSphere(Win3D, i.p, .1);
		DrawArrow(Win3D, i.p, 1.2 * i.n, .05);
	}
	Win3D.SwapBuffers();
}

void Application::ResizeMainWindow(size_t w, size_t h)
{
}

void Application::Resize3DWindow(size_t w, size_t h)
{
	Win3D.SetCameraPos(5, 5, 5);
	Win3D.SetCameraTarget(0, 0, 0);
	Win3D.SetCameraUp(0, 0, 1);
}

void main()
{
	Application app;

	EventLoop();
}

