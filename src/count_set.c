#include "../inc/pathfinder.h"

int count_set(char **array, char *new_islands) {
    int count = 0;

    if (array && *array) {
        if (array[0]) {
            count++;
        }

        int j = 0;

        for (int i = 1; array[i] != NULL; i++) {
            if (mx_isdigit(array[i][0])) {
                i++;
            }
            if (array[i] == NULL) {
                break;
            }

            for (j = i - 1; j >= 0; j--) {
                if (mx_strcmp(array[i], array[j]) == 0) {
                    break;
                }
                if (j == 0) {
                    count++;
                }
            }
        }
    }

    if (count == 0 || count != mx_atoi(new_islands) || count == 1) {
        error_invalid_number_of_islands();
    }

    return count;
}
