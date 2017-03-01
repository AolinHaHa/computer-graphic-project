#include "win.h"
#include "point.h"
#include "ray.h"
#include "polygon.h"
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
	polygon p;

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
	Win.SetText("Intersecting a Polygon");

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

	for (int i = 0; i < 6; i++)
		p.AddPoint(point(-1.5 * sin(2*PI*i/6), 1.5 * cos(2*PI*i/6), 1.5 * sin(2*PI*i/6)));
	p.CalculateNormal();

	SetupControls();
	Win.Show();
}

void Application::SetupControls(void)
{

	RayBox.Setup(Win, 435, 185, 180, 230, "Ray's Data", Button::GroupBox);
	PosXLabel.Setup(RayBox, 10, 20, 150, 20, "Position X");
	PosXScroll.Setup(RayBox, 10, 35, RayBox.Width() - 20, 15, 0, 1000, 1000, 100);
	PosXScroll.SetChangeEvent(this, &Application::RayScrollChanged);
	PosXScroll.SetScrollEvent(this, &Application::RayScrollChanged);

	PosYLabel.Setup(RayBox, 10, 55, 150, 20, "Position Y");
	PosYScroll.Setup(RayBox, 10, 70, RayBox.Width() - 20, 15, 0, 1000, 550, 100);
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

	Win3D.SetColor(0.0, .6, 0.0);
	DrawSphere(Win3D, R.p, .08);
	DrawLine(Win3D, R.p, R.p + 1000 * R.v);
	DrawArrow(Win3D, R.p, 1.2 * R.v / R.v.Length(), .05);

	Win3D.SetColor(0.0, 0.0, 1.0);
	DrawPolygon(Win3D, p.AsArray(), p.NPoints());

	if (p.Intersect(R, i))
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

