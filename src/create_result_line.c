#include "../inc/pathfinder.h"

t_output *create_result_line(t_path *bond, char **set) {
    t_output *result = malloc(sizeof(t_output));
    int i;

    result->path = mx_strdup("Path: ");
    join(&(*result).path, set[bond->pathID]);

    result->route = mx_strdup("Route: ");
    join(&(*result).route, set[bond->pathID]);

    result->distance = mx_strdup("Distance: ");

    for (i = 0; bond; bond = bond->nextConnect) {
        i++;
    }

    result->distance_int = i;

    return result;
}
