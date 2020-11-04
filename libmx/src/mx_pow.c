#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (pow == 0) {
        return 1;
    }
    
    double res = n;

    for (unsigned int i = 1; i < pow; i++) {
        res *= n;
    }

    return res;
}
