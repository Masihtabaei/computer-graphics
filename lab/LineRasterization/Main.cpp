#include "Main.h"


#define simulateTheLineThroughOriginAndInFirstOctantUsingBresenhamAlgorithm simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV5
#define simulateTheLineThroughOriginAndInFirstOctantUsingBresenhamAlgorithmOptimized simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV8



int main()
{
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSampling(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV1(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV2(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV3(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV4(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV5(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV6(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV7(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV8(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingBresenhamAlgorithm(4, 3));
	displayTheResults(simulateTheLineThroughOriginAndInFirstOctantUsingBresenhamAlgorithmOptimized(4, 3));
	simulateTheLineThroughOriginAndInFirstOctantUsingSignedDistanceFunctionSampling(4, 3, 4.0/5);
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSampling(
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV1(
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV2(
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV3(
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV4(
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV5(
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV6(
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
std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV7(
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

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV8(
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

std::map<int, int> simulateTheLineThroughOriginAndInFirstOctantUsingSignedDistanceFunctionSampling(
	int endPointXCoordinate,
	int endPointYCoordinate,
	double threshold)
{
	std::map<int, int> pointsInsideTheConsensusRange;
	double thresholdHalved = threshold / 2;
	for (int x = 0; x <= endPointXCoordinate; x++)
	{
		for (int y = 0; y <= endPointYCoordinate; y++)
		{
			double distanceToTheLine = (endPointXCoordinate * y - endPointYCoordinate * x) / pow(pow(endPointXCoordinate, 2) + pow(endPointYCoordinate, 2), 1/2.0);
			if (distanceToTheLine <= thresholdHalved && distanceToTheLine > -thresholdHalved)
			{
				pointsInsideTheConsensusRange[x] = y;
				std::cout << "Valid x:" << x << " Valid y: " << y << std::endl;
			}
		}
	}
	return pointsInsideTheConsensusRange;
}