#include "libmx.h"
int mx_strlen(const char *s) {
    if (!s) {
        return 0;
    }

    int len;

    for (len = 0; s[len];) {
        len++;
    }

    return len;
}
