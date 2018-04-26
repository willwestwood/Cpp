#pragma once

#include <vector>

class ColourFinder
{
private:
	int _dimensions;
	std::vector<std::vector<double>> _boundaries;
	int _resolution = 255;
public:
	ColourFinder(double xMin, double xMax);
	ColourFinder(double xMin, double xMax, double yMin, double yMax);
	ColourFinder(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax);
	std::vector<double> FindColour(std::vector<std::vector<double>> coords);
};