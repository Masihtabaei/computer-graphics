#include "IntVector2D.h"


IntVector2D::IntVector2D()
{
	xCoordinate = 0;
	yCoordinate = 0;
}


IntVector2D::IntVector2D(int xCoordinate, int yCoordinate)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
}


IntVector2D IntVector2D::add(IntVector2D rightHandSide) const
{
	return IntVector2D(xCoordinate + rightHandSide.xCoordinate, yCoordinate + rightHandSide.yCoordinate);
}

IntVector2D IntVector2D::subtract(IntVector2D rightHandSide) const
{
	return IntVector2D(xCoordinate - rightHandSide.xCoordinate, yCoordinate - rightHandSide.yCoordinate);
}

void IntVector2D::scale(int scalar)
{
	xCoordinate *= scalar;
	yCoordinate *= scalar;
}


int IntVector2D::dot(IntVector2D rightHandSide) const
{
	return
		(xCoordinate * rightHandSide.xCoordinate) +
		(yCoordinate * rightHandSide.yCoordinate);
}

IntVector2D IntVector2D::cross() const
{
	return IntVector2D(yCoordinate, -xCoordinate);
}

double IntVector2D::calculateTheNorm(int lebeseguSpaceNorm) const
{
	return (lebeseguSpaceNorm == INFINITY_NORM
		? (xCoordinate > yCoordinate ? xCoordinate : yCoordinate)
		: (pow(pow(xCoordinate, lebeseguSpaceNorm) + pow(yCoordinate, lebeseguSpaceNorm), 1.0 / lebeseguSpaceNorm)));
}


int IntVector2D::getTheXCoordinate() const
{
	return xCoordinate;
}

int IntVector2D::getTheYCoordinate() const
{
	return yCoordinate;
}

bool IntVector2D::equals(IntVector2D rightHandSide) const
{
	return
		(xCoordinate == rightHandSide.xCoordinate) &&
		(yCoordinate == rightHandSide.yCoordinate);
}

std::string IntVector2D::getTheFormattedString() const
{
	return "(" + std::to_string(xCoordinate) + ", " + std::to_string(yCoordinate) + ")";
}