#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include<GL/glew.h>
#include<GL/GL.h>
#include<string>
#include<sstream>
#include"DrawUtils.h"
#include"AABB.h"

// A static sprite. Sprite does not have the ability to move

class Sprite {
public:
	Sprite();
	Sprite(GLuint, int, int, float, float);
	void draw();
	void update(float);
	void sethasCollided(bool);
	AABB& getBox();
	AABB box;
	std::string to_string() const;
protected:
	GLuint texture;
	float x;
	float y;
	int width;
	int height;
	bool hasCollided;
};

#endif