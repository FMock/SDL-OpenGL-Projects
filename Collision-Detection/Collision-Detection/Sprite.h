#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include<GL/glew.h>
#include<GL/GL.h>
#include"DrawUtils.h"
#include"AABB.h"

// A static sprite

class Sprite {
public:
	Sprite();
	Sprite(GLuint, int, int, float, float);
	void draw();
	void sethasCollided(bool);
	AABB& getBox();
	AABB box;
protected:
	GLuint texture;
	float x;
	float y;
	int width;
	int height;
	bool hasCollided;
};

#endif