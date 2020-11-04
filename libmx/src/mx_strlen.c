#include "libmx.h"

int mx_strlen(const char *s) {
    int counter = 0;
    const char *s_count = s;

    while (*s_count++) {
        counter++;
    }

    return counter;
}
