#include "list.h"
#include "my.h"

int count_s_nodes(struct s_node* head){
	if (head == NULL){
        return 0;
    }
    struct s_node * curr;
    curr = head;
    int result = 1;
	while(curr -> next != NULL){
		result++;
		curr = curr -> next;
	}
	return result;
}