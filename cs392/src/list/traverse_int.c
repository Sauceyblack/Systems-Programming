#include "list.h"
#include "my.h"

void traverse_int(struct s_node* head){
	if (head == NULL){
        my_str("Cannot use node with a NULL pointer");
        return;
    }
    struct s_node * curr;
    curr = head;
    while(curr -> next != NULL){
    	int *relem = (int *) curr -> elem;
    	my_int(*relem);
    	curr = curr -> next;
    }
}