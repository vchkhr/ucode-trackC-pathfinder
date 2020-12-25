#include "../inc/pathfinder.h"

void add_link(t_path **current_path_pointer, t_path **new) {
    t_path *current_path = *current_path_pointer;

    for (; current_path->nextConnect; current_path = current_path->nextConnect) {
        current_path->nextPath = *new;
    }
    
    current_path->nextPath = *new;
}
