#include "list.h"
#include "my.h"

struct s_node* node_at(struct s_node* head, int n){
	if (head == NULL){
        my_str("Cannot return node with a NULL pointer");
        return NULL;
    }
    struct s_node * curr;
    curr = head;
    if(n == 0){
    	return curr;
    }
	for(int i = 0; i < n; i++){
		if(curr-> next == NULL){
    			return curr;
		}
		curr = curr -> next;
	}
	return curr;
}
