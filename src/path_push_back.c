#include "../inc/pathfinder.h"

void path_push_back(t_path **path, t_path **previous, int isl, int dist) {
    t_path *current = *previous;
    t_path *new = NULL;
    t_path *last = *path;
    
    for (; last->nextPath != NULL;) {
        last = last->nextPath;
    }
    for (; current; current = current->nextPath) {
        new = add_one_path(&current, isl, dist);

        if (get_unique_path(&new, &(*path)) == 1) {
            add_link(&last, &new);

            last = last->nextPath;
        }
    }
}
