#include "../inc/pathfinder.h"

void print_result_line(t_output **prd) {
    print_delimiter();
    mx_printstr((*prd)->path);
    mx_printstr((*prd)->route);
    mx_printstr((*prd)->distance);

    print_delimiter();
    mx_strdel(&(*prd)->path);
    mx_strdel(&(*prd)->route);
    mx_strdel(&(*prd)->distance);

    free(*prd);

    *prd = NULL;
}
