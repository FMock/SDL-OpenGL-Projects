#include"GLDrawFrameTester.h"

GlDrawFrameTester::GlDrawFrameTester(){}

GlDrawFrameTester::GlDrawFrameTester(GLuint image, float x, float y, int nRows, int nCols) 
	: image(image), 
	x(x), 
	y(y), 
	numberOfRows(nRows), 
	numberOfColumns(nCols), 
	currentFrame(Frame(0.0, (1.0/numberOfColumns), 0.0, (1.0/numberOfRows))), 
	colDivision(1.0/numberOfColumns), 
	rowDivision(1.0/numberOfRows){}

void GlDrawFrameTester::draw(){
	// Temporarilly entered 100, 100 for the frame width and height respectively
	// since these are the specs of the test image
	// Also the test image (test-sheet.tga) has 8 columns and 6 rows
	glDrawFrame(image, x, y, 100, 100, currentFrame.s1, currentFrame.s2, currentFrame.t1, currentFrame.t2);
}

void GlDrawFrameTester::update(float deltaTime){
	x += 5.0 * deltaTime; // temporarily use 5.0 as change_x
	y += 5.0 * deltaTime; // temporarily use 5.0 as change_y
}

void GlDrawFrameTester::nextFrameRight(){
	currentFrame.setS1(currentFrame.column * colDivision);
	currentFrame.setS2((currentFrame.column * colDivision) + colDivision);
	currentFrame.setT1(currentFrame.row * rowDivision);
	currentFrame.setT2((currentFrame.row * rowDivision) + rowDivision);
}

void GlDrawFrameTester::nextFrameLeft(){

}

void GlDrawFrameTester::nextFrameUp(){

}

void GlDrawFrameTester::nextFrameDown(){

}