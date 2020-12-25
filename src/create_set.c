#include "../inc/pathfinder.h"

void create_set(char ***set, char ***array, char *new_islands) {
    int count = count_set(*array, new_islands);
    
    *set = (char **)malloc((count + 1) * sizeof(char *));
    **set = NULL;
    
    char **array_x2 = *array;
    char **set_array = *set;

    for (int i = 0, flag = 0; *array_x2; flag = 0) {
        if (mx_isdigit(**array_x2)) {
            array_x2++;
        }
        if (*array_x2) {
            flag = create_flag(*array_x2, set_array);

            if (flag != 0) {
                array_x2++;

                continue;
            }
            if (flag == 0) {
                set_array[i] = mx_strdup(*array_x2);
                set_array[i + 1] = NULL;
                i++;
            }

            array_x2++;
        }
    }
}
