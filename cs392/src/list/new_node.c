#include "list.h"
#include "my.h"

struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous) {
    /*
    Allocates memory and constructs a new node
    */

    struct s_node* newnode = (struct s_node*)malloc(sizeof(struct s_node));

    newnode->elem = elem; 
    newnode->next = next;
    newnode->prev = previous;
    return newnode;

}