#include "../inc/pathfinder.h"

int **create_matrix(char **set, char ***array_x3) {
    int **matrix = NULL;
    int i = 0;

    for (; set[i];) {
        i++;
    }

    int j = i;
    
    matrix = malloc(sizeof(int*) * i);

    for (; j >= 0; j--) {
        matrix[j] = malloc(sizeof(int) * i);
    }

    process_matrix(set, *array_x3, &matrix);
    
    return matrix;
}
