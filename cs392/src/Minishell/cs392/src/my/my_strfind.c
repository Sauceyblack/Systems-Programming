#include "my.h"

char* my_strfind(char* word, char letter) {

	/* This function returns the pointer to the first char that matches */

	if (word == NULL) {
		return NULL;
	}
    if (my_strlen(word) == 0) {
        return NULL;
    }
	char *tempstring = word;

	while (*tempstring != letter) {
		if (*tempstring == '\0') {
			return NULL;
		}
		tempstring++;	
	}
	return tempstring;
}