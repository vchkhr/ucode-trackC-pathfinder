#include "../inc/pathfinder.h"

void swap(t_path **distance, t_path **bond, t_path **fastest) {
    t_path *temp = (*fastest)->nextPath;
    t_path *current = *distance;

    if ((*bond)->nextPath == *fastest) {
        add_link(&(*fastest), &(*bond));
        add_link(&(*bond), &temp);

        if (*distance == *bond) {
            *distance = *fastest;
        }
        else {
            for (; current && current->nextPath != *bond;) {
                current = current->nextPath;
            }

            add_link(&current, &(*fastest));
        }
    }
    else {
        swap_distance(&(*distance), &(*bond), &(*fastest));
    }
}
