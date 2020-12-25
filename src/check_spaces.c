#include "../inc/pathfinder.h"

void check_spaces(char **lines, char *file) {
    char *file_str = file;

    if (*file_str == '\n') {
        error_line_is_not_valid(1);
    }

    char **lines_str = lines;
    int i = 0;
    int length = 0;

    for (; *file_str; file_str++) {
        if (*file_str == '\n' && *(file_str + 1) == '\n') {
            for (; lines_str[i]; i++) {
                length = mx_strlen(lines_str[i]);

                if (mx_strncmp(file_str - length, lines_str[i], mx_strlen(lines_str[i])) == 0) {
                    error_line_is_not_valid(i + 2);
                }
            }
        }
    }
}
