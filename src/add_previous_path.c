#include "../inc/pathfinder.h"

t_path *add_previous_path(t_path **previous) {
    t_path *new = NULL;
    t_path *last = *previous;
    t_path *result = NULL;

    result = create_path(last->pathID, last->pathDistance);
    new = result;

    for (last = last->nextConnect; last; new = new->nextConnect) {
        new->nextConnect = create_path(last->pathID, last->pathDistance);
        last = last->nextConnect;
    }

    return result;
}
