#include "../inc/pathfinder.h"

void island_pop_front(t_island **head) {
    if (!head || !(*head)) {
        return;
    }

    t_island *island = NULL;
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;

        return;
    }

    island = (*head)->next;
    free(*head);
    *head = island;
}
