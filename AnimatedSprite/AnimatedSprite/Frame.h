#pragma once
#ifndef FRAME_H
#define FRAME_H

struct Frame
{
	inline Frame() {};
	inline Frame(float s1, float s2, float t1, float t2) 
		: s1(s1), s2(s2), t1(t1), t2(t2), row(0), column(0){}

	float s1, s2, t1, t2;
	int row, column;

	inline void setS1(float s) { this->s1 = s; }
	inline void setS2(float s) { this->s2 = s; }
	inline void setT1(float t) { this->t1 = t; }
	inline void setT2(float t) { this->t2 = t; }
	inline void setRow(int r) { this->row = r; }
	inline void setColumn(int c) { this->column = c; }
};

#endif // !FRAME_H
