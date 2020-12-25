#include "../inc/pathfinder.h"

t_path *copy_path(t_path **data) {
    t_path *current = NULL;
    t_path *result = NULL;
    t_path *new = NULL;
    t_path *fastest = NULL;

    if (*data) {
        current = *data;
    }

    result = add_previous_path(&current);
    fastest = result;

    for (current = current->nextPath; current; current = current->nextPath) {
        new = add_previous_path(&current);

        add_link(&fastest, &new);

        fastest = fastest->nextPath;
    }
    
    return result;
}
