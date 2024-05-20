#pragma once

#include "Foundation.h"
#include "IntVector2D.h"

class Line2D
{
private:
	double slope;
	double intercept;
public:
	Line2D();
	Line2D(double slope, double intercept);
	Line2D(IntVector2D firstPoint, IntVector2D secondPoint);

	double getTheSlope(void) const;
	double getTheIntercept(void) const;

	bool checksWhetherTheGivenPointLiesOnTheLine(IntVector2D pointToCheck);
	IntVector2D determineTheIntersectionPointWithAnotherLine(Line2D anotherLine);
};