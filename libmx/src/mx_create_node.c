#include "libmx.h"

t_list *mx_create_node(void *data) {
    if (!data) {
        return NULL;
    }

    t_list *new_list = malloc(16);

    if (!new_list) {
        return NULL;
    }

    new_list->data = data;
    new_list->next = NULL;

    return new_list;
}
