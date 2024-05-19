#include "Main.h"
#include <iostream>



int main()
{
	simulateTheLineUsingNaiveLinearFunctionSampling(4, 3);
	std::cout << "---------" << std::endl;
	simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV1(4, 3);
	std::cout << "---------" << std::endl;
	simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV2(4, 3);

}

/*

	Problems:
		- (Recurrent) Division
		- (Recurrent) Multiplication
		- (Recurrent) Rounding (-> recurrent function calls)
		- Double as data type
		- Recurrent variable creation (continousY and discreteY)

*/
void simulateTheLineUsingNaiveLinearFunctionSampling(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		double continuousY = ((double) endPointYCoordinate / endPointXCoordinate) * x;
		int discreteY = round(continuousY);
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}
}

/*

	Problems:
		- (One time) Division
		- (Recurrent) Rounding (-> recurrent function calls)
		- Double as data type
*/
void simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV1(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	double slope = ((double) endPointYCoordinate / endPointXCoordinate);
	double continuousY = -slope;
	int discreteY = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		continuousY += slope;
		discreteY = round(continuousY);
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}
}


void simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV2(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	double slope = ((double)endPointYCoordinate / endPointXCoordinate);
	double continuousY = -slope;
	int discreteY = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		continuousY += slope;
		discreteY = round(continuousY);
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}
}