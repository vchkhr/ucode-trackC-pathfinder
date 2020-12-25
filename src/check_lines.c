#include "../inc/pathfinder.h"

void check_lines(char **lines, int line_number) {
    for (int i = 0, j = 0, n = 1; n <= line_number; n++) {
        for (i = 0, j = 0; mx_isalpha(lines[n][i]);) {
            i++;
        }

        if (i == 0 || lines[n][i] != '-') {
            print_invalid(n);
        }

        for (i++, j = i; mx_isalpha(lines[n][j]);) {
            j++;
        }

        if (j - i == 0 || lines[n][j] != ',') {
            print_invalid(n);
        }

        for (j++, i = j; mx_isdigit(lines[n][j]);) {
            j++;
        }

        if (j - i == 0 || lines[n][j] != '\0') {
            print_invalid(n);
        }
    }
}
