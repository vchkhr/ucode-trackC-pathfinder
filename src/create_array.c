#include "../inc/pathfinder.h"

void create_array(char **lines, char ***arr_x3) {
    int position = 1;

    for (; lines[position];) {
        position++;
    }

    *arr_x3 = (char **)malloc((position * 3 + 1) * sizeof(char *));
    fill_islands(&(*arr_x3), lines, 1);
}
