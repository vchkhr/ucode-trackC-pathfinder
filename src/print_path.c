#include "../inc/pathfinder.h"

void print_path(t_path **path, int destination, char **set) {
    t_output *result = NULL;
    char *distance = mx_itoa(destination);

    for (t_path *bond = *path ; bond; bond = bond->nextPath) {
        result = create_result_line(bond, set);

        for (bond = bond->nextConnect; bond->nextConnect; bond = bond->nextConnect) {
            add_next_bond(&result, bond, distance, set);
        }

        add_next_bond(&result, bond, distance, set);
        print_result_line(&result);
    }

    mx_strdel(&distance);
}
