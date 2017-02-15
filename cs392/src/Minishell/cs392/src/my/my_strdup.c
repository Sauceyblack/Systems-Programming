#include "my.h"

char *my_strdup(char *str) {
	/* Allocates new memory and copies stirng into that memory*/
	if(str == NULL) {
		return NULL;
	}
	int memlen = my_strlen(str);

	char *newstring;

	newstring = (char *) malloc(memlen + 1);
	for (int i = 0; i < memlen; i++) {
		newstring[i] = str[i];
	}
	newstring[memlen] = '\0';
	return newstring;
}