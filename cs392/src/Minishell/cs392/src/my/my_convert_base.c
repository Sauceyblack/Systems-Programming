#include "my.h"

int* my_convert_base(int number, int base){
    int i = 0;
    int result [68];
    while(number > 0){
        int remain = number % base;
        number = number / base;
        result[i] =remain * my_power(10, i);
        i++;
    }
    int * resultp = result;
    return resultp;

}