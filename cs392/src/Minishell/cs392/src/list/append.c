#include "list.h"
#include "my.h"

void append(struct s_node* node, struct s_node** head){

    if (node == NULL || node->elem == NULL){
        my_str("Cannot add a NULL element");
        return;
    }

    if(head == NULL) {
        my_str("Cannot pass a NULL head");
        return;
    }
    if (*head == NULL) {
        *head = node;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return;
    }
    
    struct s_node *curr;
    curr = *head;
    while(curr->next != NULL){
    	curr=curr->next;
    }
    curr->next = node;
    node->prev = curr;
    node->next = NULL;
}