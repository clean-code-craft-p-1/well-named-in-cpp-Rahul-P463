#pragma once
#include <iostream>
#include "TelcoColorCoder.h"

const char* MajorColorNames[]   = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[]   = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMinorColors		    = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
int numberOfMajorColors		    = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber)
{
	int zeroBasedPairNumber = pairNumber - 1;
	MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
	MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
	return ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor)
{
	return major * numberOfMinorColors + minor + 1;
}

TelCoColorCoder::MajorColor TelCoColorCoder::ColorPair::getMajor() { return majorColor; }
TelCoColorCoder::MinorColor TelCoColorCoder::ColorPair::getMinor() { return minorColor; }

std::string TelCoColorCoder::ColorPair::ToString()
{
	std::string colorPairStr = MajorColorNames[majorColor];
	colorPairStr += " ";
	colorPairStr += MinorColorNames[minorColor];
	return colorPairStr;
}

void TelCoColorCoder::ColorManual(const char* majorColor, int numberOfMajorColor, const char* minorColor, int numberOfMinorColor)
{
	std::cout << "PairNumber" << "  " << "MajorColor" << "     " << "MinorColor" << std::endl;
	int pairNumber = 1;
	for (int majorColorIndex = 0; majorColorIndex < numberOfMajorColor; majorColorIndex++)
	{
		for (int minorColorIndex = 0; minorColorIndex < numberOfMinorColor; minorColorIndex++)
		{
			std::cout << pairNumber << "\t\t\t" << majorColor[majorColorIndex] << "\t\t\t" << minorColor[minorColorIndex] << std::endl;
			pairNumber++;
		}
	}
}