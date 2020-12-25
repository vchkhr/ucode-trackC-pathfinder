#include "../inc/pathfinder.h"

void process_next_step(t_path **old, t_path **path, t_path **new) {
    *path = *new;
    *old = (*old)->nextPath;
}
