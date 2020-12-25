#include "../inc/pathfinder.h"

t_island *create_island(int islandID, int distance) {
    t_island *island = (t_island *)malloc(sizeof(t_island));

    island->islandID = islandID;
    island->destination = distance;
    island->path = NULL;
    island->next = NULL;
    
    return island;
}
