#include "list.h"
#include "my.h"

void* elem_at(struct s_node* head, int n){
    if (head == NULL) {
        return NULL;
    }
	struct s_node * rnode;
	rnode = node_at(head, n);
	return rnode -> elem;
}