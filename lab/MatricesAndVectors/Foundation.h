#pragma once

#include <string>

#define _USE_MATH_DEFINES
#include <cmath>


constexpr int MANHATTAN_NORM = 1;
constexpr int TAXI_CAB_NORM = 1;
constexpr int EUCLIDEAN_NORM = 2;
constexpr int INFINITY_NORM = -1;


class NoIntersectionPointException : public std::exception {
private:
	std::string exceptionMessage;
public:
	NoIntersectionPointException(const std::string& message) : exceptionMessage(message) {}
	const char* what() const noexcept override {
		return exceptionMessage.c_str();
	}
};


