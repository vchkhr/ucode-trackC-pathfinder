#include "../inc/pathfinder.h"

void pop_next_path(t_path **head) {
    if (!head || !(*head)) {
        return;
    }

    t_path *path = NULL;

    if ((*head)->nextPath == NULL) {
        free(*head);
        *head = NULL;

        return;
    }
    
    path = (*head)->nextPath;
    free(*head);
    *head = path;
}
