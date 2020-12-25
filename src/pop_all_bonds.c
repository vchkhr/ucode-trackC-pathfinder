#include "../inc/pathfinder.h"

void pop_all_bonds(t_path **head) {
    t_path *path = NULL;

    if (!head || !(*head)) {
        return;
    }

    for (; (*head)->nextConnect; *head = path) {
        path = (*head)->nextConnect;
        free(*head);
    }

    if (!(*head)->nextConnect && !(*head)->nextPath) {
        free(*head);
        *head = NULL;

        return;
    }
}
