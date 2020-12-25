#include "libmx.h"

static int file_len(const char *file_name) {
    if (!file_name) {
        return 0;
    }

    int file = open(file_name, O_RDONLY);

    if (file < 0) {
        close(file);

        return 0;
    }

    int len = 0;

    for (char buf; read(file, &buf, 1);) {
        len++;
    }

    return len;
}

char *mx_file_to_str(const char *file_name) {
    if (!file_name) {
        return NULL;
    }

    int file = open(file_name, O_RDONLY);

    if (file < 0) {
        close(file);

        return NULL;
    }

    int filelen = file_len(file_name);
    
    if (filelen == 0) {
        return NULL;
    }

    char *str = mx_strnew(filelen);
    read(file, str, filelen);
    close(file);
    
    return str;
}
