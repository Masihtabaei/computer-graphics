#include "Main.h"

int main()
{
	clipTheLineUsingCohenSutherlandAlgorithm(0, 0, 0, 0, 0, 0, 0, 0);
}

void clipTheLineUsingCohenSutherlandAlgorithm(
	int startPointXCoordinat,
	int startPointYCoordinate,
	int endPointXCoordinate,
	int endPointYCoordinate,
	int bottomLeftEdgeOfViewingWindowXCoordinate,
	int topLeftEdgeOfViewingWindowYCoordinate,
	int bottomRightEdgeOfViewingWindowXCoordinate,
	int topRightEdgeOfViewingWindowYCoordinate
)
{
	std::cout << "Bottom: " << BOTTOM_OF_VIEWING_WINDOW_OUT_CODE_MASK << std::endl;
	std::cout << "Right: " << RIGHT_OF_VIEWING_WINDOW_OUT_CODE_MASK << std::endl;
	std::cout << "Top: " << TOP_OF_VIEWING_WINDOW_OUT_CODE_MASK << std::endl;
	std::cout << "Left: " << LEFT_OF_VIEWING_WINDOW_OUT_CODE_MASK << std::endl;


}