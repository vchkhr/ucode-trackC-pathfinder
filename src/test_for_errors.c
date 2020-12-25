#include "../inc/pathfinder.h"

void test_for_errors(int argc, char *file, char **argv) {
    if (argc != 2) {
        error_invalid_arguments();
    }
    if (open(argv[1], O_RDONLY) < 0) {
        error_file_not_exist(argv[1]);
    }
    if (mx_strlen(file) == 0) {
        error_file_empty(argv[1]);
    }

    char **lines = mx_strsplit(file, '\n');
    int new_line = 0;
    
    for (; lines[new_line];) {
        new_line++;
    }

    if (lines[0][0] == '0') {
        error_invalid_number_of_islands();
    }

    for (int position = 0; lines[0][position]; position++) 
    {
        if (!mx_isdigit(lines[0][position])) {
            error_line_1_is_not_valid();
        }
    }

    check_lines(lines, new_line - 1);
    check_spaces(lines, file);
    mx_del_strarr(&lines);
}
