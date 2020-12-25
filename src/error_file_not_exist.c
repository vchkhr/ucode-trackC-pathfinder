#include "../inc/pathfinder.h"

void error_file_not_exist(char *file_name) {
    mx_printerr("error: file ");
    mx_printerr(file_name);
    mx_printerr(" does not exist\n");
    
    exit(0);
}
