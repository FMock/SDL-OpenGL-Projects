#pragma once
#ifndef ANIMATIONDEF_H
#define ANIMATIONDEF_H

//#include"animation.h"
#include<vector>
#include<map>

class AnimationDef {
public:
	AnimationDef();

	/* AnimationDef.h
	 * param b - total rows on the spritesheet
	 * param c - frameWidth
	 * param d - frameHeight
	 * param anims - a reference to a vector of animation objects
	 * param aMap - mapping of animation names to it's index in the aniamtions vector
	 * The animationMap member contains a mapping of each animations textual name to it's
	 * index position in the animation list. main.cpp can use this mapping to do a lookup to check
	 * and possibly change an animation when the player presses certain keys.
	 */

	void update(float);
};

#endif