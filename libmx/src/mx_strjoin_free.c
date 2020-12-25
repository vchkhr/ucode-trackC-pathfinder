#include "libmx.h"

char *mx_strjoin_free(char const *s1, char const *s2) {
    if (!s1 && !s2) {
        return NULL;
    }

    if (!s1 && s2) {
        return mx_strdup(s2);
    }

    if (s1 && !s2) {
        return mx_strdup(s1);
    }

    char *new_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    new_str = mx_strcat(mx_strcpy(new_str, s1), s2);

    char *to_delete = (char*)s1;
    
    mx_strdel(&to_delete);
    
    return new_str;
}
