#include "../inc/pathfinder.h"

t_path_list *create_path_list() {
    t_path_list *path_list = malloc(sizeof(t_path_list));

    path_list->unvisited = NULL;
    path_list->visited = NULL;
    path_list->current = NULL;
    path_list->shortest = NULL;
    
    return path_list;
}
