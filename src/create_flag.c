#include "../inc/pathfinder.h"

int create_flag(char *array_x2, char **set_array) {
    for (int flag = 0, i = 0; set_array[i]; i++) {
        if (mx_strcmp(array_x2, set_array[i]) == 0) {
            return flag + 1;
        }
    }

    return 0;
}
