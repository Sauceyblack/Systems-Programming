#include "my.h"
#include "list.h"

void print_char(struct s_node* node){
    if (node == NULL) {
        my_str("NULL");
        return;
    }
	char * nelem = (char *) node -> elem;
	my_char(*nelem);
}