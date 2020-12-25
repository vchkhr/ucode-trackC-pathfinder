#include "../inc/pathfinder.h"

void swap_distance(t_path **distance, t_path **bond, t_path **fastest) {
    t_path *temp = (*fastest)->nextPath;
    t_path *current = *distance;

    for (; current->nextPath != *fastest;) {
        current = current->nextPath;
    }

    add_link(&current, &(*bond));
    current = *distance;

    if (*distance == *bond) {
        *distance = *fastest;
    }
    else {
        for (; current && current->nextPath != *bond;) {
            current = current->nextPath;
        }

        add_link(&current, &(*fastest));
    }

    add_link(&(*fastest), &(*bond)->nextPath);
    add_link(&(*bond), &temp);
}
