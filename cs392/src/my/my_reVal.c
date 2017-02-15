#include "my.h"

char my_reVal(int num) {
	if (num >= 0 && num <= 9) {
		return (char)(num + '0');
	}
	else {
		return (char)(num - 10 + 'A');
	}
}