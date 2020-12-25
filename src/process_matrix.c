#include "../inc/pathfinder.h"

void process_matrix(char **set, char **arrarr, int ***matrix) {
    t_size_int *size_int = malloc(sizeof(t_size_int));
    
    for (size_int->size = 0; set[size_int->size]; size_int->size += 1) {
        for (size_int->root = 0; arrarr[size_int->root]; size_int->root += 1) {
            if (mx_strcmp(set[size_int->size], arrarr[size_int->root]) == 0) {
                fill_matrix(set, arrarr, &(*matrix), size_int);
            }
        }
    }

    free(size_int);
    size_int = NULL;
}
