#include <iostream>
#include <string>
#include "ColourFinder.h"

int main(int argc, char * argv[])
{
	// hue
	ColourFinder finder(0, 240);
	std::vector<double> res = finder.FindColour({ {17}, {1}, {32}, {94}, {226}, {140}, {212}, {160}, {154}, {132}, {112}, {16}, {120}, {60}, {175}, {193} });
	std::cout << "Based on hue: " << res[0] << std::endl;

	ColourFinder finder2(0, 255, 0, 255, 0, 255);
	std::vector<double> res2 = finder2.FindColour({
		{255, 0, 0 },
		{29,193,0},
		{0,107,225}
		/*{ 137, 78, 36 },
		{ 220, 36, 31 },
		{ 255, 206, 0 },
		{ 0, 114, 41 },
		{ 215, 153, 175 },
		{ 134, 143, 152 },
		{ 117, 16, 86 },
		{ 0, 0, 0 },
		{ 0, 25, 168 },
		{ 0, 160, 226 },
		{ 118, 208, 189 },
		{ 255, 102, 0 },
		{ 0, 153, 153 },
		{ 102, 204, 0 },
		{ 97, 65, 153 }*/
	});
	std::cout << "Based on rgb: " << res2[0] << " " << res2[1] << " " << res2[2] << std::endl;

	std::string s;
	std::cin >> s;
}