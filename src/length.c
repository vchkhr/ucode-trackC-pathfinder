#include "../inc/pathfinder.h"

void length(t_path_list **path_list, int **matrix, char **set) {
    (*path_list)->shortest = shortest_distance(&(*path_list)->unvisited);

    pbi(&(*path_list)->visited, &(*path_list)->shortest->path, (*path_list)->shortest->islandID, (*path_list)->shortest->destination);
    island_pop_middle(&(*path_list)->unvisited, (*path_list)->shortest->islandID);

    (*path_list)->current = (*path_list)->current->next;

    if ((*path_list)->current->path == NULL) {
        delete_matrix(&matrix, set);
        error_invalid_number_of_islands();

        exit(0);
    }
}
