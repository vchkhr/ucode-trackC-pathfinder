#include "../inc/pathfinder.h"

int main (int argc, char *argv[]) 
{
    char *file = mx_file_to_str(argv[1]);
    test_for_errors(argc, file, argv);

    int **matrix = NULL;
    char **set = NULL;

    parse_file(file, &matrix, &set);
    pathfinder(matrix, set);
    
    delete_matrix(&matrix, set);
    mx_strdel(&file);
    mx_del_strarr(&set);
    
    return 0;
}
