#include "../inc/pathfinder.h"

void compare_pathes(t_path **new, t_path **current, int *flag) {
    if (*new && *current) {
        if ((*new)->pathID != (*current)->pathID) {
            *flag = 1;
        }
        if ((*new)->pathDistance != (*current)->pathDistance) {
            *flag = 1;
        }
    }
    if (!(*new) || !(*current)) {
        *flag = 1;
    }
}
