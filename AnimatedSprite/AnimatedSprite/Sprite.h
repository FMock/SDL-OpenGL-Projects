#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include<GL/glew.h>
#include<GL/GL.h>
#include<string>
#include<sstream>
#include"DrawUtils.h"
#include"AABB.h"
#include"Vector2D.h"

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
	void setX(float x);
	void setY(float y);
	std::string to_string() const;
protected:
	GLuint texture;
	float x;
	float y;
	float change_x;
	float change_y;
	int width;
	int height;
	void setWidth(int);
	void setHeight(int);
	Vector2D position;
	bool hasCollided;
};

#endif