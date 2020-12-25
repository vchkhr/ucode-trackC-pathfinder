#include "../inc/pathfinder.h"

void fill_matrix(char **set, char **array, int ***matrix, t_size_int *size_int) {
    int root = size_int->root;
    int **matrix_x2 = *matrix;
    int x = size_int->size;
    int y = 0;

    if (mx_isdigit(array[root + 1][0])) {
        for (; mx_strcmp(set[y], array[root - 1]) != 0;) {
            y++;
        }

        if (!matrix_x2[x][y] || matrix_x2[x][y] > mx_atoi(array[root + 1])) {
            matrix_x2[x][y] = mx_atoi(array[root + 1]);
        }
    } 
    else {
        for (; mx_strcmp(set[y], array[root + 1]) != 0;) {
            y++;
        }

        if (!matrix_x2[x][y] || matrix_x2[x][y] > mx_atoi(array[root + 2])) {
            matrix_x2[x][y] = mx_atoi(array[root + 2]);
        }
    }
}
