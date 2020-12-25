#include "../inc/pathfinder.h"

void fill_islands(char ***arr_x3, char **lines, int line) {
    int position = 0;
    char *distance = NULL;
    char *island1 = NULL;
    char *island2 = NULL;
    char **arr_x2 = *arr_x3;

    for (; lines[line]; line++) {
        get_line_from_array(lines[line], &island1, &island2, &distance);
        
        if (mx_strcmp(island1, island2) == 0 && mx_atoi(distance) != 0) {
            error_line_is_not_valid(line + 1);
        }

        arr_x2[position++] = mx_strdup(island1);
        mx_strdel(&island1);

        arr_x2[position++] = mx_strdup(island2);
        mx_strdel(&island2);

        arr_x2[position++] = mx_strdup(distance);
        mx_strdel(&distance);

        for (int i = 0; i < position - 3; i += 3) {
            if (mx_strcmp(arr_x2[position - 3], arr_x2[i]) == 0 && 
                mx_strcmp(arr_x2[position - 2], arr_x2[i + 1]) == 0) {
                error_duplicate_bridges();
            }
            if (mx_strcmp(arr_x2[position - 2], arr_x2[i]) == 0 && 
                mx_strcmp(arr_x2[position - 3], arr_x2[i + 1]) == 0) {
                error_duplicate_bridges();
            }
        }
    }
}
