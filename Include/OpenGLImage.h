/////////////////////////////////////////////////////////////////////////////
//
// OpenGLImage.h : interface of the OpenGLImage class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __OPENGLIMAGE_H__
#define __OPENGLIMAGE_H__

// Include the OpenGL headers
#include "gl\gl.h"
#include "gl\glu.h"
//#include "gl\glaux.h"

class ImageData
{
 public:
     GLint sizeX, sizeY;
     unsigned char *data;

     ImageData(int w, int h) 
	  { sizeX = w; sizeY = h; data = new GLubyte[w*h*3]; }

     ~ImageData()
	  { delete [] data; }

     GLubyte &operator[](int i) { return(data[i]); }
     GLubyte &operator()(int i, int j, int k)
	  { return(data[3*(sizeX * j + i) + k]); }	  

	 ImageData &operator=(const ImageData &img)
	 { sizeX = img.sizeX; sizeY = img.sizeY; 
		memcpy(data, img.data, sizeX*sizeY*3*sizeof(unsigned char)); 
		return(*this); }
};

class OpenGLImage
{
// Attributes
public:

// Operations
public:
	OpenGLImage(const char *name = "None", BOOL MipMap = FALSE, GLint mode = GL_MODULATE);

	const char *GetDIBFileName() 
		{ return m_DIBFileName; }

   	BOOL InitFromDIB(const char *, GLint = GL_MODULATE);
   	BOOL SelectImage( );

	virtual ~OpenGLImage();

// Implementation
protected:


private:
	char m_DIBFileName[255];
	ImageData* m_pRGBImage;
	GLint   m_TextureFunction;
	GLuint  m_TextureID;
 	BOOL mipmap;

#ifdef _DEBUG
#endif
protected:


};

/////////////////////////////////////////////////////////////////////////////

#endif
