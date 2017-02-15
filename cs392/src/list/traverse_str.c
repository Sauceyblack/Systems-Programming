#include "list.h"
#include "my.h"

void traverse_str(struct s_node* head){
	if (head == NULL){
        my_str("Cannot use node with a NULL pointer");
        return;
    }
    struct s_node * curr;
    curr = head;
    while(curr -> next != NULL){
    	my_str(curr -> elem);
    	curr = curr -> next;
    }
}