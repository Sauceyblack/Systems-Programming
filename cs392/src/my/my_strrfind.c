#include "my.h"

char* my_strrfind(char* word, char letter) {

	/* This function returns a pointer to the last char that matches */

	if (word == NULL) {
		return NULL;
	}

	char *tempstring = word;

	tempstring = tempstring + my_strlen(word);

	while (*tempstring != letter) {
		tempstring--;
		if (*tempstring == '\0' && letter != word[0]) {
			return NULL;
		}
	}
	return tempstring;
}