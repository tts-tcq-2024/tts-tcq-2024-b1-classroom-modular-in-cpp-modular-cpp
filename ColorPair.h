#ifndef COLORPAIR_H
#define COLORPAIR_H

#include "ColorDefs.h"
#include <string>

namespace TelCoColorCoder 
{
    class ColorPair {
        private:
            MajorColor majorColor;
            MinorColor minorColor;
        public:
            ColorPair(MajorColor major, MinorColor minor);
            MajorColor getMajor();
            MinorColor getMinor();
            std::string ToString();
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void PrintColorCodingReference();
}

#endif
