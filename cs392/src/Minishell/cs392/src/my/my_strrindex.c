#include "my.h"

int my_strrindex(char *word,char letter) {

	/*Returns the last index at which this character appears*/
	
	char *tempword = word;
	tempword = tempword + my_strlen(word);

	for (int i = my_strlen(word); i > 0; i--) {
		if (*tempword == letter) {
			return i;
		}
		tempword--;
	}
	return -1;
}