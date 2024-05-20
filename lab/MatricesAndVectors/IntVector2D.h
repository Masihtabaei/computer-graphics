#pragma once

#include "Foundation.h"


class IntVector2D
{
private:
	int xCoordinate;
	int yCoordinate;

public:
	IntVector2D();
	IntVector2D(int xCoordinate, int yCoordinate);

	IntVector2D add(IntVector2D rightHandSide) const;
	IntVector2D subtract(IntVector2D rightHandSide) const;
	void scale(int scalar);
	int dot(IntVector2D rightHandSide) const;
	IntVector2D cross() const;

	double calculateTheNorm(int lebeseguSpaceNorm) const;

	int getTheXCoordinate() const;
	int getTheYCoordinate() const;

	bool equals(IntVector2D rightHandSide) const;
	std::string getTheFormattedString() const;
};



