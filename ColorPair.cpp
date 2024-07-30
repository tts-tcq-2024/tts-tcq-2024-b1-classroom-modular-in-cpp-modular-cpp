#include "ColorPair.h"
#include <iostream>

namespace TelCoColorCoder 
{
    ColorPair::ColorPair(MajorColor major, MinorColor minor) :
        majorColor(major), minorColor(minor)
    {}

    MajorColor ColorPair::getMajor() {
        return majorColor;
    }

    MinorColor ColorPair::getMinor() {
        return minorColor;
    }

    std::string ColorPair::ToString() {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
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
        for (int major = 0; major < numberOfMajorColors; ++major) {
            for (int minor = 0; minor < numberOfMinorColors; ++minor) {
                ColorPair colorPair = ColorPair((MajorColor)major, (MinorColor)minor);
                int pairNumber = GetPairNumberFromColor((MajorColor)major, (MinorColor)minor);
                std::cout << "Pair Number: " << pairNumber << ", Colors: " << colorPair.ToString() << std::endl;
            }
        }
    }
}
