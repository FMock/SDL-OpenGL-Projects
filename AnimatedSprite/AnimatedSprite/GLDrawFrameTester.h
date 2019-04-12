#pragma once
#ifndef GLDRAWFRAMETESTER_H
#define GLDRAWFRAMETESTER_H
	
#include<GL/glew.h>
#include<GL/GL.h>
#include<string>
#include<sstream>
#include"DrawUtils.h"
#include"Frame.h"


class GlDrawFrameTester{
public:
	GlDrawFrameTester();
	GlDrawFrameTester(GLuint image, float x, float y, int nRows, int nCols);
	void draw();
	void update(float);
	void nextFrameRight();
	void nextFrameLeft();
	void nextFrameUp();
	void nextFrameDown();
	void setRowDivision(float);
	void setColDivision(float);
	float x; // The x position to draw current frame on screen
	float y; // The y position to draw current frame on screen
	Frame currentFrame;
	GLuint image;
	float colDivision;
	float rowDivision;
	int numberOfRows;
	int numberOfColumns;
	std::string to_string() const;
private:
	void updateSandT();
};

#endif // !GLDRAWFRAMETESTER_H
