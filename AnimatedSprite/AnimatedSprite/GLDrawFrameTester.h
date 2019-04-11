#pragma once
#ifndef GLDRAWFRAMETESTER_H
#define GLDRAWFRAMETESTER_H
	
#include<GL/glew.h>
#include<GL/GL.h>
#include"DrawUtils.h"
#include"Frame.h"


class GlDrawFrameTester{
	GlDrawFrameTester();
	GlDrawFrameTester(GLuint image, float x, float y, int nRows, int nCols);
	void draw();
	void update(float);
	void nextFrameRight();
	void nextFrameLeft();
	void nextFrameUp();
	void nextFrameDown();
	float x; // The x position to draw current frame on screen
	float y; // The y position to draw current frame on screen
	Frame currentFrame;
	GLuint image;
	float colDivision;
	float rowDivision;
	int numberOfRows;
	int numberOfColumns;
};

#endif // !GLDRAWFRAMETESTER_H
