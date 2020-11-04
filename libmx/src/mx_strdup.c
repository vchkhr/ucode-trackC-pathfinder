#include "libmx.h"

char *mx_strdup(const char *s1) {
    int size = mx_strlen(s1);
    char *res = mx_strnew(size);
    
    res = mx_strcpy(res, s1);

    return res;
}
