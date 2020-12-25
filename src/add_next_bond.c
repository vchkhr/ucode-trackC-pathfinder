#include "../inc/pathfinder.h"

void add_next_bond(t_output **prd, t_path *bond, char *destination, char **set) {
    char *distance = mx_itoa(bond->pathDistance);
    
    join(&(*prd)->route, " -> ");
    join(&(*prd)->route, set[bond->pathID]);

    if (mx_strlen((*prd)->distance) != 10) {
        join(&(*prd)->distance, " + ");
    }

    join(&(*prd)->distance, distance);
    mx_strdel(&distance);

    if (bond->nextConnect == NULL) {
        join(&(*prd)->path, " -> ");
        join(&(*prd)->path, set[bond->pathID]);

        if ((*prd)->distance_int != 2) {
            join(&(*prd)->distance, " = ");
            join(&(*prd)->distance, destination);
        }

        join(&(*prd)->route, "\n");
        join(&(*prd)->path, "\n");
        join(&(*prd)->distance, "\n");
    }
}
