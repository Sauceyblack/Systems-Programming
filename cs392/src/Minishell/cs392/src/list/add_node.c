#include "list.h"
#include "my.h"

void add_node(struct s_node* node, struct s_node** head) {
    /*
    Inserts a node at the start of the list, Cannot take NULL elements or pointers
    */
    if(node == NULL || node->elem == NULL || head == NULL) {
        my_str("Non-null arguments only.");
        return;
    }
    if (*head == NULL) {
        *head = node;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return;
    }
    
    (*head)->prev = node;
    node->next = *head;
    *head = node;
    
}