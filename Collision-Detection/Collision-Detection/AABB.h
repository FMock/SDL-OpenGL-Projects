#pragma once
#ifndef AABB_H
#define AABB_H

/* AABB represents the invisible box around a sprite that is
   used for checking collisions with other boxes*/

struct AABB {
	inline AABB() {}
	inline AABB(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
	int x, y, w, h;
	inline void setX(int x) { this->x = x; }
	inline void setY(int y) { this->y = y; }
	inline void setW(int w) { this->w = w; }
	inline void setH(int h) { this->h = h; }

	// returns true if this box collides (interectss) with another box
	inline bool boxesIntersect(AABB box2) {

		//this box is to the right of box2
		if (x > box2.x + box2.w) {
			return false;
		}

		// this box is to the left of box2
		if (x + w < box2.x) {
			return false;
		}

		// this box is below box2
		if (y > box2.y + box2.h) {
			return false;
		}

		// this box is above box2
		if (y + h < box2.y) {
			return false;
		}

		return true;
	}

};
#endif