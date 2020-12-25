#include "../inc/pathfinder.h"

void error_file_empty(char *file_name) {
    mx_printerr("error: file ");
    mx_printerr(file_name);
    mx_printerr(" is empty\n");
    
    exit(0);
}
