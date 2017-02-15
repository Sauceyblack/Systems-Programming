#include "list.h"
#include "my.h"

void add_elem(void* elem, struct s_node** head) {
    /*
    Creates a node with elem and adds to to the head
    */
    if (head == NULL || elem == NULL) {
        my_str("Cannot add NULL head");
    }
    else {
        struct s_node *node = new_node(elem, NULL, NULL);
        add_node(node, head);
    }
}