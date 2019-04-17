#include"GLDrawFrameTester.h"

GlDrawFrameTester::GlDrawFrameTester(){}

GlDrawFrameTester::GlDrawFrameTester(GLuint image, float x, float y, int nRows, int nCols) 
	: image(image), 
	x(x), 
	y(y), 
	numberOfRows(nRows), 
	numberOfColumns(nCols), 
	currentFrame(Frame(0.0, (float(1.0/float(numberOfColumns))), 0.0, (float(1.0/float(numberOfRows))))), 
	colDivision(float(1.0/numberOfColumns)), 
	rowDivision(float(1.0/numberOfRows)){

	// These initializations were necessary since above initializations didn't work
	rowDivision = float(1.0 / float(numberOfRows));
	colDivision = float(1.0 / float(numberOfColumns));
	currentFrame.s2 = float(1.0 / float(numberOfColumns));
	currentFrame.t2 = float(1.0 / float(numberOfRows));
}

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

void GlDrawFrameTester::updateSandT() {
	currentFrame.setS1(currentFrame.column * colDivision);
	currentFrame.setS2((currentFrame.column * colDivision) + colDivision);
	currentFrame.setT1(currentFrame.row * rowDivision);
	currentFrame.setT2((currentFrame.row * rowDivision) + rowDivision);
}

void GlDrawFrameTester::nextFrameRight(){
	currentFrame.column = (currentFrame.column + 1) % numberOfColumns;
	updateSandT();
}

void GlDrawFrameTester::nextFrameLeft(){
	currentFrame.column = (currentFrame.column -1) % numberOfColumns;
	updateSandT();
}

void GlDrawFrameTester::nextFrameUp(){
	currentFrame.row = (currentFrame.row + 1) % numberOfRows;
	updateSandT();
}

void GlDrawFrameTester::nextFrameDown(){
	currentFrame.row = (currentFrame.row - 1) % numberOfRows;
	updateSandT();
}

void GlDrawFrameTester::setRowDivision(float rowDiv)
{
	this->rowDivision = rowDiv;
}

void GlDrawFrameTester::setColDivision(float colDiv)
{
	this->colDivision = colDiv;
}

std::string GlDrawFrameTester::to_string() const
{
	std::ostringstream oss;

	oss << "rowDivision " << rowDivision << "\n"
		<< "colDivision " << colDivision << "\n"
		<< "Frame s1 " << currentFrame.s1 << "\n"
		<< "Frame s2 " << currentFrame.s2 << "\n"
		<< "Frame t1 " << currentFrame.t1 << "\n"
		<< "Frame t2 " << currentFrame.t2 << "\n"
		<< "X " << x << "\n"
		<< "y " << y << "\n";
		
	return oss.str();
}
