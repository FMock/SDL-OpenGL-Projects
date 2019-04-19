#pragma once
#ifndef GLDRAWFRAMETESTER_H
#define GLDRAWFRAMETESTER_H

#include<GL/glew.h>
#include<GL/GL.h>
#include<string>
#include<sstream>
#include<vector>
#include"DrawUtils.h"
#include"Animation.h"
#include"Frame.h"


class GlDrawFrameTester {
public:
	GlDrawFrameTester();
	GlDrawFrameTester(GLuint image, float x, float y, int nRows, int nCols, int fWidth, int fHeight);
	void draw();
	void update(float);
	void setRowDivision(float);
	void setColDivision(float);
	float x; // The x position to draw current frame on screen
	float y; // The y position to draw current frame on screen
	float change_x;
	float change_y;
	Frame currentFrame;
	GLuint image;
	float colDivision;
	float rowDivision;
	int numberOfRows;
	int numberOfColumns;
	int frameWidth;
	int frameHeight;
	std::string to_string() const;
	int getCurrentAnimation()const;
	void setCurrentAnimation(unsigned int);
	void setAnimFPS(float);
	float getAnimFPS() const;
private:
	float frameTime; // the amount of time the current frame has been displayed
	float animFPS;   // default is 24.0f
	std::vector<Animation> animations;
	int currentAnimation;
};

#endif // !GLDRAWFRAMETESTER_H
