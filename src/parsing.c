#include "../inc/pathfinder.h"

void parse_file(char *file, int ***matrix, char ***set) {
    char **arr_x2 = NULL;
    char **src = mx_strsplit(file, '\n');

    create_array(src, &arr_x2);
    create_set(&(*set), &arr_x2, src[0]);

    *matrix = create_matrix(*set, &arr_x2);
    
    mx_del_strarr(&src);
    mx_del_strarr(&arr_x2);
}
