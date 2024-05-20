#pragma once

#include "Foundation.h"


class Int2DVector
{
private:
	int xCoordinate;
	int yCoordinate;

public:
	Int2DVector();
	Int2DVector(int xCoordinate, int yCoordinate);

	Int2DVector add(Int2DVector rightHandSide) const;
	Int2DVector subtract(Int2DVector rightHandSide) const;
	void scale(int scalar);
	int dot(Int2DVector rightHandSide) const;
	Int2DVector cross() const;

	double calculateTheNorm(int lebeseguSpaceNorm) const;

	int getTheXCoordinate() const;
	int getTheYCoordinate() const;

	bool equals(Int2DVector rightHandSide) const;
	std::string getTheFormattedString() const;
};



