#include "Int2DVector.h"


Int2DVector::Int2DVector()
{
	xCoordinate = 0;
	yCoordinate = 0;
}


Int2DVector::Int2DVector(int xCoordinate, int yCoordinate)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
}


Int2DVector Int2DVector::add(Int2DVector rightHandSide) const
{
	return Int2DVector(xCoordinate + rightHandSide.xCoordinate, yCoordinate + rightHandSide.yCoordinate);
}

Int2DVector Int2DVector::subtract(Int2DVector rightHandSide) const
{
	return Int2DVector(xCoordinate - rightHandSide.xCoordinate, yCoordinate - rightHandSide.yCoordinate);
}

void Int2DVector::scale(int scalar)
{
	xCoordinate *= scalar;
	yCoordinate *= scalar;
}


int Int2DVector::dot(Int2DVector rightHandSide) const
{
	return
		(xCoordinate * rightHandSide.xCoordinate) +
		(yCoordinate * rightHandSide.yCoordinate);
}

Int2DVector Int2DVector::cross() const
{
	return Int2DVector(yCoordinate, -xCoordinate);
}

double Int2DVector::calculateTheNorm(int lebeseguSpaceNorm) const
{
	return (lebeseguSpaceNorm == INFINITY_NORM
		? (xCoordinate > yCoordinate ? xCoordinate : yCoordinate)
		: (pow(pow(xCoordinate, lebeseguSpaceNorm) + pow(yCoordinate, lebeseguSpaceNorm), 1.0 / lebeseguSpaceNorm)));
}


int Int2DVector::getTheXCoordinate() const
{
	return xCoordinate;
}

int Int2DVector::getTheYCoordinate() const
{
	return yCoordinate;
}

bool Int2DVector::equals(Int2DVector rightHandSide) const
{
	return
		(xCoordinate == rightHandSide.xCoordinate) &&
		(yCoordinate == rightHandSide.yCoordinate);
}

std::string Int2DVector::getTheFormattedString() const
{
	return "(" + std::to_string(xCoordinate) + ", " + std::to_string(yCoordinate) + ")";
}