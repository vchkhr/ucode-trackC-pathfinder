#include "../inc/pathfinder.h"

t_island *shortest_distance(t_island **unvisited) {
    t_island *head = NULL;
    t_island *shortest = NULL;

    if (unvisited || *unvisited) {
        for (head = *unvisited, shortest = *unvisited; head; head = head->next) {
            if (head->destination != 0) {
                if (shortest->destination > head->destination || !shortest->destination) {
                    shortest = head;
                }
            }
        }
    }
    
    return shortest;
}
