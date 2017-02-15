#include "my.h"

void my_str(char* s) {
	
	/*Prints NULL terminated string to console*/

	if (s == NULL) {
	return;
}
	while (*s != '\0') {
		my_char(*s);
		s++;
	}
}