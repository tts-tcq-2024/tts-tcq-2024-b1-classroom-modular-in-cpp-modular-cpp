#include "ColorDefs.h"

namespace TelCoColorCoder 
{
    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
}
