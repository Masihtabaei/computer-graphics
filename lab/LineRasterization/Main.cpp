#include "Main.h"
#include <iostream>



int main()
{
	simulateTheLineUsingNaiveLinearFunctionSampling(4, 3);
}

void simulateTheLineUsingNaiveLinearFunctionSampling(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		double continousY = ((double) endPointYCoordinate / endPointXCoordinate) * x;
		int discreteY = round(continousY);
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}
}