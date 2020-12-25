#include "../inc/pathfinder.h"

void median(t_island **unvisited, t_island **current, int **mat, t_matrix **matrix) {
    int sum = 0;

    for (t_island *island = *unvisited; island != NULL; island = island->next) {
        (*matrix)->island1 = (*current)->islandID;
        (*matrix)->island2 = island->islandID;
        (*matrix)->matrix = mat[(*matrix)->island1][(*matrix)->island2];

        if ((*matrix)->matrix != 0 && island->destination == 0) {
            island->destination = (*current)->destination + (*matrix)->matrix;
            sum += island->destination;

            if (sum < 0) { 
                error_sum_of_bridges_lengths_is_too_big();
            } 

            island->path = add_path(&(*current)->path, (*matrix)->island2, (*matrix)->matrix);
        } else if ((*matrix)->matrix != 0) {
            if ((*current)->destination + (*matrix)->matrix == island->destination) {
                path_push_back(&island->path, &(*current)->path, (*matrix)->island2, (*matrix)->matrix);
            }
            if ((*current)->destination + (*matrix)->matrix < island->destination) {
                island->destination = (*current)->destination + (*matrix)->matrix;
                delete_path(&island->path);
                island->path = add_path(&(*current)->path, (*matrix)->island2, (*matrix)->matrix);
            }
        }
    }
}
