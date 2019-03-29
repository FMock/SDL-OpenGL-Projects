#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include<GL/glew.h>
#include<GL/GL.h>
#include"DrawUtils.h"

// A static sprite

class Sprite {
public:
	Sprite();
	Sprite(GLuint, int, int, float, float);
	void draw();
	GLuint texture;
	float x;
	float y;
	int width;
	int height;
};

#endif