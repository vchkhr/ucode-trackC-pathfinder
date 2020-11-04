#include "libmx.h"

void mx_printstr(const char *s) {
    int counter = mx_strlen(s);

    write(1, s, counter);
}
