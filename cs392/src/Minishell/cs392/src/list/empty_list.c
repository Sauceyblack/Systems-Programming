#include "list.h"
#include "my.h"

void empty_list(struct s_node** head) {
    if (head == NULL) {
        my_str("Cannot empty a list with a null head");
        return;
    }
    struct s_node* current = *head;
    struct s_node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}