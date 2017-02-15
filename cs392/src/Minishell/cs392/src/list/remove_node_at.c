#include "list.h"
#include "my.h"

void* remove_node_at(struct s_node** head, int n){
    if (head == NULL) {
        return NULL;
    }
	if ((*head) == NULL){
        return NULL;
    }
    if(n <= 0) {
        return remove_node(head);
    }

    struct s_node* ptr = *head;
    int i = 0;

    while(i <= n-1) {
        if (ptr->next == NULL) {
            return remove_last(head);
        }
        
        ptr = ptr->next;
        i++;
    }

    void* ret = ptr->elem;

    if(ptr->next == NULL) {
        ptr->prev->next = NULL;
    }
    else if(n == 0) {
        ptr->next->prev = NULL;
        *head = ptr->next;
    }
    else {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
    }

    free(ptr);
    return ret;
}