#include "my.h"

char *my_strcpy(char *dst, char *src) {
	/*Copies contents of src and puts them into dst*/
    if (dst == NULL) {
        return NULL;;
    }
    if (src == NULL) {
        return NULL;;
    }
	char *srcarray = src;
    
	while(*srcarray != '\0') {
		*dst = *srcarray;
		dst++;
		srcarray++;
	}
	*dst = '\0';
	return dst;
}