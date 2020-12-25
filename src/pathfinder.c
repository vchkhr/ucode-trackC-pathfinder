#include "../inc/pathfinder.h"

void pathfinder(int **matrix, char **set) {
    int size = 0;

    for (; set[size];) {
        size++;
    }

    t_size_int *size_int = malloc(sizeof(t_size_int));
    size_int->size = size;

    for (int i = 0; i < size - 1; i++) {
        size_int->root = i;
        algorithm(matrix, set, size_int);
    }

    free(size_int);
    size_int = NULL;
}
