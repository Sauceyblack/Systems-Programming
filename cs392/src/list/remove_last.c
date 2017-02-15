#include "list.h"
#include "my.h"

void* remove_last(struct s_node** head){
    if (head == NULL) {
        my_str("Can't remove node that doesn't exist");
        return NULL;
    }
	if ((*head) == NULL){
        my_str("The list is empty");
        return NULL;
    }
    if ((*head)->prev == NULL && (*head)->next == NULL) {
        void *ret = (*head)->elem;
        *head = NULL;
        return ret;
    }
    struct s_node* ptr = *head;

    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;

    void* ret = ptr->elem;

    free(ptr);
    return ret;
}