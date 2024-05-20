#pragma once

#include "Foundation.h"
#include "IntVector2D.h"
#include "Line2D.h"

#include <exception>



class IntLineSegment2D
{
private:
	IntVector2D startingPoint;
	IntVector2D endingPoint;
	Line2D parentLine;
	bool isCulled;

public:
	IntLineSegment2D();
	IntLineSegment2D(IntVector2D endingPoint);
	IntLineSegment2D(IntVector2D endingPoint, bool isCulled);
	IntLineSegment2D(IntVector2D startingPoint,  IntVector2D endingPoint);
	IntLineSegment2D(IntVector2D startingPoint,  IntVector2D endingPoint, bool isCulled);

	IntVector2D getTheStartingPoint(void) const;
	IntVector2D getTheEndingPoint(void) const;
	bool getTheCullingState(void) const;
	double getTheSlope(void) const;

	bool checkWhetherTheGivenPointLiesOnTheLineSegment(IntVector2D pointToCheck);
	IntVector2D determineTheIntersectionPointWithAnotherLineSegment(IntLineSegment2D anotherLineSegment);
	IntVector2D determineTheIntersectionPointWithAnotherLine(Line2D anotherLine);
};