#include "my.h"

int my_strindex(char* word, char letter){
    /* returns the first index at which a character appears */

    char *wordcopy = word;

    for (int i = 0; i < my_strlen(wordcopy); i++) {
    	if (*wordcopy == letter) {
    		return i;
    	}
    	wordcopy++;
    }
    return -1;
}