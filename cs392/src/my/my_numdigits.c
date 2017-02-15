#include "my.h"

int my_numdigits(int n) {
	int temp = n;
    int count = 0;
    while (temp!= 0) {
    	temp = temp/10;
    	++count;
    }
    return count;
}