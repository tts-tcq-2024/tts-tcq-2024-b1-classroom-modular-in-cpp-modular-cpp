#include <iostream>
#include <iomanip>
#include "ColorCoder.h"

namespace TelCoColorCoder 
{
    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    ColorPair::ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor) {}
    MajorColor ColorPair::getMajor() const { return majorColor; }
    MinorColor ColorPair::getMinor() const { return minorColor; }
    std::string ColorPair::ToString() const {
        return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    void PrintColorCodingReference() {
        std::cout << std::left << std::setw(15) << "Pair Number" << std::setw(15) << "Major Color" << "Minor Color" << std::endl;
        for (int pairNumber = 1; pairNumber <= numberOfMajorColors * numberOfMinorColors; ++pairNumber) {
            ColorPair colorPair = GetColorFromPairNumber(pairNumber);
            std::cout << std::setw(15) << pairNumber << std::setw(15) << MajorColorNames[colorPair.getMajor()] << MinorColorNames[colorPair.getMinor()] << std::endl;
        }
    }
}
