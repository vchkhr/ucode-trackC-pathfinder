#include "../inc/pathfinder.h"

t_island *create_island(int isl, int dist) {
    t_island *node = (t_island *)malloc(1 * sizeof(t_island));

    node->indexIsland = isl;
    node->distTo = dist;
    node->path = NULL;
    node->next = NULL;
    
    return node;
}
