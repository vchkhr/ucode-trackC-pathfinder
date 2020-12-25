#include "../inc/pathfinder.h"

void process_path(t_island **unvisited, t_island **current, t_island **visited, t_size_int *size_int) {
    *visited = NULL;
    *unvisited = NULL;

    for (int i = 0; i < size_int->size; i++) {
        pbi(&(*unvisited), NULL, i, 0);
    }

    *current = *unvisited;

    for (; (*current)->islandID != size_int->root;) {
        *current = (*current)->next;
    }

    (*current)->path = create_path(size_int->root, 0);

    pbi(&(*visited), &(*current)->path, (*current)->islandID, (*current)->destination);
    island_pop_middle(&(*unvisited), size_int->root);

    *current = *visited;
}
