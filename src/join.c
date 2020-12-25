#include "../inc/pathfinder.h"

void join(char **result, char *string) {
    char *new_string = mx_strnew(mx_strlen(*result) + mx_strlen(string));
    int position = -1;
    int n = 0;

    for (char *string_test = *result; string_test[++position]; n++) {
        new_string[n] = string_test[position];
    }

    for (position = -1; string[++position]; n++) {
        new_string[n] = string[position];
    }

    mx_strdel(&(*result));
    *result = new_string;
}
