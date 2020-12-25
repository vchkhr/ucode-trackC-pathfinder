#include "../inc/pathfinder.h"

t_path *add_one_path(t_path **previous, int island, int distance) {
    t_path *last = *previous;
    t_path *result = NULL;

    if (!last) {
        result = create_path(island, distance);
        
        return result;
    }

    t_path *new_path = NULL;

    result = create_path(last->pathID, last->pathDistance);
    new_path = result;
    last = last->nextConnect;

    for (; last; last = last->nextConnect, new_path = new_path->nextConnect) {
        new_path->nextConnect = create_path(last->pathID, last->pathDistance);
    }
    
    new_path->nextConnect = create_path(island, distance);

    return result;
}
