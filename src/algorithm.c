#include "../inc/pathfinder.h"

void algorithm(int **matrix_x2, char **set, t_size_int *size_int) {
    t_path_list *path_list = create_path_list();
    t_matrix *matrix = NULL;

    process_path(&path_list->unvisited, &path_list->current, &path_list->visited, size_int);

    for (; path_list->unvisited && path_list->unvisited != NULL;) {
        matrix = malloc(sizeof(t_matrix));
        median(&path_list->unvisited, &path_list->current, matrix_x2, &matrix);
        free(matrix);
        matrix = NULL;
        length(&path_list, matrix_x2, set);
    }

    print_result(&path_list->visited, size_int->root+1, size_int->size, set);

    for (; path_list->visited != NULL;) {
        delete_path(&path_list->visited->path);
        island_pop_front(&path_list->visited);
    }

    free(path_list);
    path_list = NULL;
}
