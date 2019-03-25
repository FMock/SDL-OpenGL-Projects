#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include<GL/glew.h>
#include<GL/GL.h>
#include"DrawUtils.h"

class Sprite {
public:
	Sprite();
	Sprite(GLuint, int, int, float, float);
	void draw();
	void update(float);
	GLuint texture;
	float x;
	float y;
	int width;
	int height;
};

#endif