#include "../inc/pathfinder.h"

int compare_fast(t_path *bond, t_path *fastest) {
    for (; bond && fastest; bond = bond->nextConnect, fastest = fastest->nextConnect) {
        if (bond->pathID > fastest->pathID) {
            return 1;
        }
        if (bond->pathID < fastest->pathID) {
            return 0;
        }
    }

    if (bond && !fastest) {
        return 1;
    }

    return 0;
}
