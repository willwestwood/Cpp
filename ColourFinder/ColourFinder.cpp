#include "ColourFinder.h"
#include <iostream>
#include <cmath>

ColourFinder::ColourFinder(double xMin, double xMax)
{
	_dimensions = 1;

	std::vector<double> xBoundaries = { xMin, xMax };
	_boundaries.push_back(xBoundaries);
}

ColourFinder::ColourFinder(double xMin, double xMax, double yMin, double yMax)
{
	_dimensions = 2;

	std::vector<double> xBoundaries = { xMin, xMax };
	std::vector<double> yBoundaries = { yMin, yMax };
	_boundaries.push_back(xBoundaries);
	_boundaries.push_back(yBoundaries);
}

ColourFinder::ColourFinder(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax)
{
	_dimensions = 3;

	std::vector<double> xBoundaries = { xMin, xMax };
	std::vector<double> yBoundaries = { yMin, yMax };
	std::vector<double> zBoundaries = { zMin, zMax };
	_boundaries.push_back(xBoundaries);
	_boundaries.push_back(yBoundaries);
	_boundaries.push_back(zBoundaries);
}

std::vector<double> ColourFinder::FindColour(std::vector<std::vector<double>> coords)
{
	double xIncrement = (_boundaries[0][1] - _boundaries[0][0]) / _resolution;

	if (_dimensions == 1)
	{
		double maxDist = 0;
		std::vector<double> maxPos = { 0.0l };

		for (double p = _boundaries[0][0]; p <= _boundaries[0][1]; p = p + xIncrement)
		{
			double min = -1;
			for (int i = 0; i < coords.size(); i++)
			{
				if (coords[i].size() != 1)
				{
					std::cout << "Coordinate number " << (i + 1) << " contains " << coords[i].size() << " dimensions!" << std::endl;
					continue;
				}

				double dist = std::abs(coords[i][0] - p);
				if (min == -1)
				{
					min = dist;
				}
				else
				{
					if (min > dist)
					{
						min = dist;
					}
				}

				if (min == 0)
					break;
			}

			if (min > maxDist)
			{
				maxDist = min;
				while(maxPos.size() > 0)
					maxPos.pop_back();
				maxPos.push_back(p);
			}
		}

		return maxPos;
	}
	else
	{
		double yIncrement = (_boundaries[1][1] - _boundaries[1][0]) / _resolution;

		if (_dimensions == 2)
		{
			double maxDist = 0;
			std::vector<double> maxPos = { 0.0l, 0.0l };

			for (double px = _boundaries[0][0]; px <= _boundaries[0][1]; px = px + xIncrement)
			{
				for (double py = _boundaries[1][0]; py <= _boundaries[1][1]; py = py + yIncrement)
				{
					double min = -1;
					for (int i = 0; i < coords.size(); i++)
					{
						if (coords[i].size() != 2)
						{
							std::cout << "Coordinate number " << (i + 1) << " contains " << coords[i].size() << " dimensions!" << std::endl;
							continue;
						}

						double dist = std::sqrt(std::pow(std::abs(coords[i][0] - px), 2) + std::pow(std::abs(coords[i][1] - py), 2));
						if (min == -1)
						{
							min = dist;
						}
						else
						{
							if (min > dist)
							{
								min = dist;
							}
						}

						if (min == 0)
							break;
					}

					if (min > maxDist)
					{
						maxDist = min;
						while (maxPos.size() > 0)
							maxPos.pop_back();
						maxPos.push_back(px);
						maxPos.push_back(py);
					}
				}
			}

			return maxPos;
		}
		else
		{
			double zIncrement = (_boundaries[2][1] - _boundaries[2][0]) / _resolution;

			double maxDist = 0;
			std::vector<double> maxPos = { 0.0l, 0.0l, 0.0l };

			for (double px = _boundaries[0][0]; px <= _boundaries[0][1]; px = px + xIncrement)
			{
				std::cout << (px / _boundaries[0][1]) * 100 << "% done..." << std::endl;
				for (double py = _boundaries[1][0]; py <= _boundaries[1][1]; py = py + yIncrement)
				{
					for (double pz = _boundaries[2][0]; pz <= _boundaries[2][1]; pz = pz + zIncrement)
					{
						double min = -1;
						for (int i = 0; i < coords.size(); i++)
						{
							if (coords[i].size() != 3)
							{
								std::cout << "Coordinate number " << (i + 1) << " contains " << coords[i].size() << " dimensions!" << std::endl;
								continue;
							}

							double dist = std::sqrt(std::pow(std::abs(coords[i][0] - px), 2) + std::pow(std::abs(coords[i][1] - py), 2) + std::pow(std::abs(coords[i][2] - pz), 2));
							if (min == -1)
							{
								min = dist;
							}
							else
							{
								if (min > dist)
								{
									min = dist;
								}
							}

							if (min == 0)
								break;
						}

						if (min > maxDist)
						{
							maxDist = min;
							while (maxPos.size() > 0)
								maxPos.pop_back();
							maxPos.push_back(px);
							maxPos.push_back(py);
							maxPos.push_back(pz);
						}
					}
				}
			}

			return maxPos;
		}
	}
}