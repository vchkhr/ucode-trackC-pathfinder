#include "libmx.h"

int mx_sqrt(int x) {
    float temp;
    float sqrt;

    if (x <= 0) {
        return 0;
    }

    sqrt = x / 2;
    temp = 0;

    while (sqrt != temp) {
        temp = sqrt;
        sqrt = (x / temp + temp) / 2;
    }

    if (sqrt - (int)sqrt == 0) {
        return sqrt;
    }

    return 0;
}
