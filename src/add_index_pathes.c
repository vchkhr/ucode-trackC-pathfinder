#include "../inc/pathfinder.h"

int add_index_pathes(t_path **path) {
    t_path *indexed = *path;
    t_path *bonds = NULL;
    int i;

    for (i = 0; indexed; indexed = indexed->nextPath, i++) {
        for (bonds = indexed; bonds; bonds = bonds->nextConnect) {
            bonds->index = i;
        }
    }
     
    return i;
}
