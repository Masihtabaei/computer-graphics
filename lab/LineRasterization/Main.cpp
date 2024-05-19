#include "Main.h"
#include <iostream>



int main()
{
	simulateTheLineUsingNaiveLinearFunctionSampling(4, 3);
	std::cout << "---------" << std::endl;
	simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV1(4, 3);
	std::cout << "---------" << std::endl;
	simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV2(4, 3);
	std::cout << "---------" << std::endl;
	simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV3(4, 3);
	std::cout << "---------" << std::endl;
	simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV4(4, 3);
	std::cout << "---------" << std::endl;
	simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV5(4, 3);
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


/*

	Problems:
		- (One time) Division
		- Double as data type
		- (Recurrent) If-else branch
*/
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
		if (continuousY - discreteY >= 0.5)
		{
			discreteY++;
		}
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}

}

/*

	Problems:
		- (Recurrent) Division
		- (Recurrent) Multiplication
		- Double as data type
		- (Recurrent) If-else branch
*/
void simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV3(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	int discreteY = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		if (((double)endPointYCoordinate / endPointXCoordinate) * x - discreteY >= 0.5)
		{
			discreteY++;
		}
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}
	
}


/*

	Problems:
		- (Recurrent) Multiplication
		- (Recurrent) If-else branch
*/
void simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV4(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	int discreteY = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		if (2 * x * endPointYCoordinate - 2 * discreteY * endPointXCoordinate >= endPointXCoordinate)
		{
			discreteY++;
		}
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}

}


/*
	Bresenham
	Problems:
		- (Recurrent) If-else branch
*/
void simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV5(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	int discreteY = 0;
	int firstTerm = 0;
	int secondTerm = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		if (2 * (firstTerm - secondTerm) >= endPointXCoordinate)
		{
			discreteY++;
			secondTerm += endPointXCoordinate;
		}

		firstTerm += endPointYCoordinate;
		std::cout << "x: " << x << " y: " << discreteY << std::endl;
	}
}


void simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV6(
	int endPointXCoordinate,
	int endPointYCoordinate)
{

}