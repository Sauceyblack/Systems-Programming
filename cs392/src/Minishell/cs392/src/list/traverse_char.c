#include "list.h"
#include "my.h"

void traverse_char(struct s_node* head){
	if (head == NULL){
        my_str("Cannot use node with a NULL pointer");
        return;
    }
    struct s_node * curr;
    curr = head;
    while(curr -> next != NULL){
    	char * relem = (char *) curr -> elem;
    	my_char(*relem);
    	curr = curr -> next;
    }
}