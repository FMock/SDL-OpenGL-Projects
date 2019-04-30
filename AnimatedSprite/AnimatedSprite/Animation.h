#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H
#include<string>
#include<GL/glew.h>
#include"Frame.h"

/* Animation.h
 * Encapsulates a single animation and it's intrinsic properties.
 */

class Animation {
public:
	Animation();

	/* Animation
	 * param a - numberOfColumns, the number of columns on spritesheet
	 * param b - numberOfRows, the number of rows this animation consists of
	 * param c - startingRow, the row this animation starts at on the spritesheet
	 * param d - textual name of this animation
	 * param rowDiv - float representing 1.0 / (spritesheet row count)
	 * param colDiv - float representing 1.0 / (spritesheet column count)
	 * param facingDirection - character facing direction shown in the animation
	 */
	Animation(int a, int b, int c, const std::string& d, float rowDiv, float colDiv, const int facingDirection);
	void nextFrame(float, float);   // draws the next frame of the animation
	Frame currentFrame; // encapsulates texture s1, s2, t1, t2 which define current frame and related info
	int getframeCount() const;
	int getTotalFrameCount() const;
	enum Parameters {COLUMNS=1, ROWS, STARTING_ROW, NAME, FACING_DIRECTION};
	static Parameters parameters;
	std::string getName() const;
private:
	int numberOfColumns; // number of frames in one row a the animation (all rows must contain the same number of columns)
	int numberOfRows;   // total number of rows for this animation
	int startingRow;    // the row this animation starts at on the spritesheet
	int currentColumn;   // initial value is 0
	float columnDivision;
	float rowDivision;
	int frameCount;     // counter - Use with totalFrameCount to track animation play cycles
	int totalFrameCount;
	std::string name;
	int facingDirection;
};
#endif