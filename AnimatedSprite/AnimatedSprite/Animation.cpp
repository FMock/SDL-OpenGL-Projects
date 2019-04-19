#include "Animation.h"

Animation::Animation() {}

/* Animation
 * param a - numberOfColumns, the number of columns on spritesheet
 * param b - numberOfRows, the number of rows this animation consists of
 * param c - startingRow, the row this animation starts at on the spritesheet
 * param d - textual name of this animation
 * param rowDiv - float representing 1.0 / (spritesheet row count)
 * param colDiv - float representing 1.0 / (spritesheet column count)
 * param facingDirection - character facing direction shown in the animation
 */
Animation::Animation(int a, int b, int c, const std::string & d, float rowDiv, float colDiv, const int facingDirection)
	:numberOfColumns(a),
	numberOfRows(b),
	startingRow(c),
	columnDivision(colDiv),
	rowDivision(rowDiv),
	frameCount(1),
	totalFrameCount(numberOfColumns * numberOfRows),
	name(d),
	facingDirection(facingDirection)
{
	currentColumn = 0;
	//currentRow = startingRow;
	currentFrame = Frame(0.0f, //s1
		columnDivision, //s2
		rowDivision * float(startingRow), //t1
		rowDivision * float(startingRow) + rowDivision); //t2

	currentFrame.row = startingRow;
}

/*
	AnimationDef calls this method in its update method
*/
void Animation::nextFrame(float frameTime, float animFPS) {

	// Calculate how many frames to jump ahead
	currentFrame.column += int(frameTime * animFPS);

	// Keep currentFrame in range
	if (currentFrame.column >= numberOfColumns)
		currentFrame.column = currentFrame.column  % numberOfColumns;

	// current row may change. Use modulus
	if (currentFrame.s2 >= 1.0 && numberOfRows > 1)
		currentFrame.row = (currentFrame.row + 1) % numberOfRows;

	// update s1, s2, t1, t2
	currentFrame.setS1(float(currentFrame.column) * columnDivision);
	currentFrame.setS2((float(currentFrame.column) * columnDivision) + columnDivision);
	currentFrame.setT1(float(currentFrame.row) * rowDivision);
	currentFrame.setT2((float(currentFrame.row) * rowDivision) + rowDivision);

	// Increment frame counter. When frameCount = 0, the last frame has been reached
	frameCount = (frameCount + 1) % totalFrameCount;
}

int Animation::getframeCount() const {
	return this->frameCount;
}

int Animation::getTotalFrameCount() const {
	return this->totalFrameCount;
}

std::string Animation::getName() const {
	return name;
}
