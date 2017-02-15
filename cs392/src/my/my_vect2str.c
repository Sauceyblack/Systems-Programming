#include "my.h"

char *my_vect2str(char **x) {
    size_t str_len;
    char*  string;
    int    idx;
    char **xcopy = x;
    str_len = 0;

    idx = 0;
    
    while (xcopy[idx] != NULL) {
        str_len += my_strlen(x[idx]);
        idx++;
    }
    idx = 0;
    
    string = malloc((str_len + 1)*sizeof(char));
    
    char* space = " ";
    
    while (x[idx] != NULL)
    {
        if (idx == 0) {
        my_strcat(string, x[idx]);
        idx++;
        }
        else {
            my_strcat(string, space);
            my_strcat(string, x[idx]);
            idx++;
        }

    }
	return string;
}