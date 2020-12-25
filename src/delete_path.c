#include "../inc/pathfinder.h"

void delete_path(t_path **head) {
    if (!head || !(*head)) {
        return;
    }
    
    for (; *head;) {
        pop_all_bonds(&(*head));
        pop_next_path(&(*head));
    }
}
