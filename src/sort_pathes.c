#include "../inc/pathfinder.h"

void sort_pathes(t_path **distance, int sizeP) {
    t_path *bond = *distance;
    t_path *fastest = (*distance)->nextPath;

    for (int i = 0; i < sizeP; i++) {
        bond = *distance;
        fastest = bond->nextPath;

        for (; bond->index != i; bond = bond->nextPath) {
            fastest = bond->nextPath;
        }

        for (; fastest;) {
            if (compare_fast(bond, fastest) == 1) {
                swap(&(*distance), &bond, &fastest);

                for (bond = *distance; bond->index != i; bond = bond->nextPath) {
                    fastest = bond->nextPath;
                }
            }
            else {
                fastest = fastest->nextPath;
            }
        }
    }
}
