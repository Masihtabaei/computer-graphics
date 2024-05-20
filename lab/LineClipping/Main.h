#pragma once

#include <iostream>

constexpr int BOTTOM_OF_VIEWING_WINDOW_OUT_CODE_MASK = 0b0001 /* Alternative: 1 */;
constexpr int RIGHT_OF_VIEWING_WINDOW_OUT_CODE_MASK =  0b0010 /* Alternatives: BOTTOM_OF_VIEWING_WINDOW_OUT_CODE_MASK << 1, multiply with 2 or simply 2 */;
constexpr int TOP_OF_VIEWING_WINDOW_OUT_CODE_MASK = 0b0100 /* Alternatives: BOTTOM_OF_VIEWING_WINDOW_OUT_CODE_MASK << 2, multiply with 4 or simply 4 */;
constexpr int LEFT_OF_VIEWING_WINDOW_OUT_CODE_MASK = 0b1000 /* Alternatives: BOTTOM_OF_VIEWING_WINDOW_OUT_CODE_MASK << 3, multiply with 8 or simply 8 */;


void clipTheLineUsingCohenSutherlandAlgorithm(
	int startPointXCoordinat,
	int startPointYCoordinate,
	int endPointXCoordinate,
	int endPointYCoordinate,
	int bottomLeftEdgeOfViewingWindowXCoordinate,
	int topLeftEdgeOfViewingWindowYCoordinate,
	int bottomRightEdgeOfViewingWindowXCoordinate,
	int topRightEdgeOfViewingWindowYCoordinate
	);
