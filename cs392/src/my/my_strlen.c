#include "my.h"

int my_strlen(char* word){
    /* returns the length of the string */
    if(word == NULL){
        return -1;
    }

    int i = 0;
    while (*word != '\0') {
    	word++;
    	i++;
    }
    return i;
}