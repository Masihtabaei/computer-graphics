#pragma once

#include <iostream>
#include <vector>
#include <map>

void displayTheResults(std::vector<int> results);

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSampling(
	int endPointXCoordinate,
	int endPointYCoordinate);

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV1(
	int endPointXCoordinate,
	int endPointYCoordinate);


std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV2(
	int endPointXCoordinate,
	int endPointYCoordinate);

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV3(
	int endPointXCoordinate,
	int endPointYCoordinate);


std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV4(
	int endPointXCoordinate,
	int endPointYCoordinate);

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV5(
	int endPointXCoordinate,
	int endPointYCoordinate);

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV6(
	int endPointXCoordinate,
	int endPointYCoordinate);

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV7(
	int endPointXCoordinate,
	int endPointYCoordinate);

std::vector<int> simulateTheLineThroughOriginAndInFirstOctantUsingNaiveLinearFunctionSamplingSelfOptimizedV8(
	int endPointXCoordinate,
	int endPointYCoordinate);

std::map<int, int> simulateTheLineThroughOriginAndInFirstOctantUsingSignedDistanceFunctionSampling(
	int endPointXCoordinate,
	int endPointYCoordinate,
	double threshold);

