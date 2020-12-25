#include "../inc/pathfinder.h"

int get_unique_path(t_path **new, t_path **current) {
    int flag = -1;
    t_path *old = *current;

    for (t_path *path = *new; old;) {
        if (old->nextConnect == NULL || !path) {
            compare_pathes(&path, &old, &flag);
            process_next_step(&old, &path, &(*new));

            if (flag == -1) {
                return flag;
            }
            if (old) {
                flag = -1;
            }

            continue;
        }

        compare_pathes(&path, &old, &flag);
        path = path->nextConnect;
        old = old->nextConnect;
    }
    
    return flag;
}
