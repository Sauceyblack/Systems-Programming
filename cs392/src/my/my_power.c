#include "my.h"

int my_power(int base, int i) {
	int result = 1;
	for (int j = 0; j < i; j++) {
		result = result * base;
	}
	return result;
}