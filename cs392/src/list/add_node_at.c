#include "list.h"
#include "my.h"

void add_node_at(struct s_node* node, struct s_node** head, int n){
	if (head == NULL){
        my_str("Cannot add node with a NULL pointer");
        return;
    }
    if (node == NULL || node->elem == NULL){
        my_str("Cannot add a NULL element");
        return;
    }
    if(n <= 0) {
        add_node(node, head);
        return;
    }

    struct s_node* current = *head;
    int i = 0;
    while (i <= n-1) {
        if (*head == NULL) {
            append(node, head);
            return;
        }
        else if (current->next == NULL) {
            append(node, head);
            return;
        }
        else {   
            current = current->next;
            i++;
        }
    }
    node->prev = current;
    node->next = current->next;
    current->next->prev = node;
    current->next = node;  

}