#include "../inc/pathfinder.h"

void island_pop_middle(t_island **unvisited, int index) {
    if (!unvisited || !(*unvisited)) {
        return;
    }
    
    t_island *temp = NULL;
    t_island *leftFirst = NULL;

    if ((*unvisited)->islandID == index) {
        delete_path(&((*unvisited)->path));
        island_pop_front(&(*unvisited));
    }
    else {
        temp = *unvisited;
        leftFirst = temp;

        for (; temp != NULL && temp->islandID != index;) {
            leftFirst = temp;
            temp = temp->next;
        }
        
        if (temp && temp->islandID == index) {
            if (temp->next) {
                leftFirst->next = temp->next;
            }
            else {
                leftFirst->next = NULL;
            }

            delete_path(&temp->path);
            free(temp);
            temp = NULL;
        }
    }
}
