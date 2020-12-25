#include "../inc/pathfinder.h"

void delete_matrix(int ***matrix, char **set) {
    int **mat = *matrix;
    int i;

    for (i = 0; set[i];) {
        i++;
    }
    for (; i >= 0; mat++, i--) {
        free(*mat);
    }

    free(*matrix);    
    *matrix = NULL;
}
