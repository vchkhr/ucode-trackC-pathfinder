#include "../inc/pathfinder.h"

void print_result(t_island **visited, int root, int size, char **set) {
    t_island *current = NULL;

    for (; root < size; root++) {
        for (current = *visited; current->islandID != root;) {
            current = current->next;
        }

        sort_pathes(&current->path, add_index_pathes(&current->path));
        print_path(&current->path, current->destination, set);
    }
}
