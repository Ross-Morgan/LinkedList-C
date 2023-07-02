#pragma once

#include<stdbool.h>

typedef struct Range {
    int low;
    int high;
    int step;
    bool inclusive;
} Range;

Range newRangeExclusive(int low, int high) {
    return (Range) { low, high, 1, false };
};

Range newRangeInclusive(int low, int high) {
    return (Range) { low, high, 1, true };
};

Range newSteppedRangeExclusive(int low, int high, int step) {
    return (Range) { low, high, step, false };
};

Range newSteppedRangeInclusive(int low, int high, int step) {
    return (Range) { low, high, step, true };
};
