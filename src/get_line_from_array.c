#include "../inc/pathfinder.h"

void get_line_from_array(char *line, char **island1, char **island2, char **distance) {
    char *string = line;
    int n = 0;
    
    for (; string[n] != '-';) {
        n++;
    }

    *island1 = mx_strndup(string, n);
    string += n + 1;

    for (n = 0; string[n] != ',';) {
        n++;
    }

    *island2 = mx_strndup(string, n);
    string += n + 1;

    for (n = 0; string[n] != '\0';) {
        n++;
    }

    *distance = mx_strndup(string, n);
}
