#include "Animation.h"

Animation::Animation(){}

/* Animation
 * param a - numberOfColumns, the number of columns on spritesheet
 * param b - numberOfRows, the number of rows this animation consists of
 * param c - startingRow, the row this animation starts at on the spritesheet
 * param d - textual name of this animation
 * param facingDirection - character facing direction shown in the animation
 */
Animation::Animation(int a, int b, int c, const std::string & d, const int facingDirection) 
	:numberOfColumns(a),
	 numberOfRows(b),
     startingRow(c),
	 columnDivision(1.0f/float(numberOfColumns)),
	 rowDivision(1.0f/float(numberOfRows)),
	 name(d),
	 facingDirection(facingDirection)
{
	currentColumn = 0;
	currentRow = startingRow;
	currentFrame = Frame(0.0f, //s1
		                 columnDivision, //s2
		                 rowDivision * float(startingRow), //t1
		                 rowDivision * float(startingRow) + rowDivision); //t2
}

void Animation::nextFrame(float frameTime, float animFPS){
	// Calculate how many frames to jump ahead
	currentColumn += frameTime * animFPS;

	// Keep currentFrame in range
	if (currentColumn >= numberOfColumns)
		currentColumn = currentColumn % numberOfColumns;

	// current row may change. Use modulus
	if (currentFrame.s2 >= 1.0 && numberOfRows > 1)
		currentRow = (currentRow + 1) % numberOfRows;

	// update s1, s2, t1, t2
	currentFrame.s1 = float(currentColumn) * columnDivision;
	currentFrame.s2 = (float(currentColumn) * columnDivision) + columnDivision;
	currentFrame.t1 = float(currentRow) * rowDivision;
	currentFrame.t2 = (float(currentRow) * rowDivision) + rowDivision;
}
