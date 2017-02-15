#include "my.h"

int my_revstr(char* word){
    /* reverses the string within the string and returns the length */
    if(word == NULL){
        return -1;
    }
    else {

        int i = my_strlen(word);

        for (char *end = word + (my_strlen(word) - 1); end > word; --end, ++word) {
            (*word) ^= (*end);
            (*end) ^= (*word);
            (*word) ^= (*end);
        }
        return i;
}
}