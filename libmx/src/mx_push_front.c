#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    if (!list || !data) {
        return;
    }

    t_list *new_head = mx_create_node(data);

    if (!new_head) {
        return;
    }

    new_head->next = (*list);
    *list = new_head;
}
