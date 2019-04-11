#ifndef DRAWUTILS_H
#define DRAWUTILS_H

#include<GL/glew.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

GLuint glTexImageTGAFile(const char* filename, int* outWidth, int* outHeight);

void glDrawSprite(GLuint tex, int x, int y, int w, int h);

/* This function is used when only part of a texture will be drawn. You must
 * pass the (s,t) texture coordinates */
void glDrawFrame(GLuint tex, int x, int y, int w, int h, float s1, float s2, float t1, float t2);

#endif