// Object for creating a post script graphics file using the same commands as the EWindow

#ifndef PSIMAGE_H
#define PSIMAGE_H

#include <fstream>
using namespace std;
 
class PSImage
{
public:

	PSImage(char *fName, double Width, double Height, double Xll, double Yll, double Xur, double Yur);
	~PSImage() { output.close(); }
	
	void WDraw(void) { output << "showpage\n"; }
	void WErase(void) { output.close(); output.open(filename); WriteHeader(); }

	void WDrawAxes(int col = -1);
	void WDrawLine(double x1, double y1, double x2, double y2, int col = -1);
	void WDrawLines(double *c, int N, int *col = NULL);
	void WDrawLines(double *x, double *y, int N, int *col = NULL);
	void WPrint(double x, double y, char *text, int rotation = 0);

private:

	void WriteHeader(void);
	
	double width, height;		// width and height of the image in inches.
	char filename[255];			// filename for the output.
	double xll, yll, xur, yur;	// bounds on the file's view.
	int BoxXll, BoxYll, BoxXur, BoxYur;
	ofstream output;
};

#endif