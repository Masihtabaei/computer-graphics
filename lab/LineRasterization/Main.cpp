#include "Main.h"


#define simulateTheLineUsingBresenhamAlgorithm simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV5 
#define imulateTheLineUsingBresenhamAlgorithmOptimized simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV8



int main()
{
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSampling(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV1(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV2(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV3(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV4(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV5(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV6(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV7(4, 3));
	displayTheResults(simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV8(4, 3));
}

void displayTheResults(std::vector<int> results)
{
	int x = 0;
	for (auto y : results)
	{
		std::cout << "x: " << x++ << " y: " << y << std::endl;
	}
	std::cout << "---------" << std::endl;
}

/*

	Problems:
		- (Recurrent) Division
		- (Recurrent) Multiplication
		- (Recurrent) Rounding (-> recurrent function calls)
		- Double as data type
		- Recurrent variable creation (continousY and discreteY)

*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSampling(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		double continuousY = ((double)endPointYCoordinate / endPointXCoordinate) * x;
		int discreteY = round(continuousY);
		yValues.push_back(discreteY);
	}
	return yValues;
}

/*

	Problems:
		- (One time) Division
		- (Recurrent) Rounding (-> recurrent function calls)
		- Double as data type
*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV1(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

	double slope = ((double)endPointYCoordinate / endPointXCoordinate);
	double continuousY = -slope;
	int discreteY = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		continuousY += slope;
		discreteY = round(continuousY);
		yValues.push_back(discreteY);
	}
	return yValues;
}


/*

	Problems:
		- (One time) Division
		- Double as data type
		- (Recurrent) If-else branch
*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV2(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

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
		yValues.push_back(discreteY);
	}

	return yValues;
}

/*

	Problems:
		- (Recurrent) Division
		- (Recurrent) Multiplication
		- Double as data type
		- (Recurrent) If-else branch
*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV3(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

	int discreteY = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		if (((double)endPointYCoordinate / endPointXCoordinate) * x - discreteY >= 0.5)
		{
			discreteY++;
		}
		yValues.push_back(discreteY);
	}
	return yValues;
}


/*

	Problems:
		- (Recurrent) Multiplication
		- (Recurrent) If-else branch
*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV4(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

	int discreteY = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		if (2 * x * endPointYCoordinate - 2 * discreteY * endPointXCoordinate >= endPointXCoordinate)
		{
			discreteY++;
		}
		yValues.push_back(discreteY);
	}
	return yValues;
}


/*
	Bresenham
	Problems:
		- (Recurrent) If-else branch
*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV5(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

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
		yValues.push_back(discreteY);
	}
	return yValues;
}


/*

	Problems:
		- (Recurrent) Multiplication
		- Recurrent casting
		- Recurrent comparison
*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV6(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

	int discreteY = 0;
	int error = -endPointXCoordinate;
	int firstIncrementingTerm = -2 * endPointXCoordinate;
	int secondIncrementingTerm = 2 * endPointYCoordinate;
	int predicateAsInteger = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		predicateAsInteger = (int)(error >= 0);
		discreteY += predicateAsInteger;
		error += predicateAsInteger * firstIncrementingTerm;
		error += secondIncrementingTerm;
		yValues.push_back(discreteY);
	}
	return yValues;
}

/*

	Problems:
		- Recurrent casting
		- Recurrent comparison
*/
std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV7(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

	int discreteY = 0;
	int error = -endPointXCoordinate;
	int firstIncrementingTerm = -2 * endPointXCoordinate;
	int secondIncrementingTerm = 2 * endPointYCoordinate;
	int predicateAsInteger = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		predicateAsInteger = -(int)(error >= 0);
		discreteY -= predicateAsInteger;
		error += (predicateAsInteger & firstIncrementingTerm) + secondIncrementingTerm;
		yValues.push_back(discreteY);
	}
	return yValues;
}

std::vector<int> simulateTheLineUsingNaiveLinearFunctionSamplingSelfOptimizedV8(
	int endPointXCoordinate,
	int endPointYCoordinate)
{
	std::vector<int> yValues;

	int discreteY = 0;
	int error = -endPointXCoordinate;
	int firstIncrementingTerm = -2 * endPointXCoordinate;
	int secondIncrementingTerm = 2 * endPointYCoordinate;
	int predicateAsInteger = 0;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		predicateAsInteger = -(int)(error >= 0);
		discreteY -= predicateAsInteger;
		error += predicateAsInteger & firstIncrementingTerm;
		error += secondIncrementingTerm;
		yValues.push_back(discreteY);
	}
	return yValues;
}