
#ifndef __OUTPUTWINDOW_H__
#define __OUTPUTWINTOW_H__

#include "window.h"

class OutputWindow : public window
{
public:

    OutputWindow(int textWidth = 80, textHeight = 25, bufferWidth = 80, 
                 int bufferHeight = 1000, int inputBufferSize = 255);
    ~OutputWindow();

    SetFont(int Width = 10, int Height = 10, char *FaceName);

private:

    int windowTextWidth;
    int windowTextHeight;
    int bufferWidth;
    int bufferHeight;
    int inputBufferSize;
    HFONT font;
    int fontWidth;
    int fontHeight;
    char faceName[100];
};

#endif