#include "../inc/pathfinder.h"

t_path *add_path(t_path **previous, int island, int distance) {
    t_path *current = NULL;
    t_path *new = NULL;
    t_path *result = NULL;
    t_path *fast = NULL;

    if (*previous) {
        current = *previous;
    }

    result = add_one_path(&current, island, distance);
    fast = result;

    if (current) {
        current = current->nextPath;
    }

    for (; current; current = current->nextPath) {
        new = add_one_path(&current, island, distance);
        add_link(&fast, &new);
        fast = fast->nextPath;
    }
    
    return result;
}
