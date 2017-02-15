#include "my.h"

char *my_strcat(char *dst, char *src) {
	
	/*Appends the src string onto the destination string
	without allocating any memory*/
	if (dst == NULL) {
		return NULL;
	}
	if (dst != NULL && src == NULL) {
		return dst;
	}

	int index = 0;
	int startindex = my_strlen(dst);
	while(src[index] != '\0') {
		dst[startindex] = src[index];
		startindex++;
		index++;
	}
	dst[startindex] = '\0';
	return dst;
	
}