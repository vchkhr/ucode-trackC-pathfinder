#include "libmx.h"

void mx_printint(int n) {
    char arr[55];
    long num = n;
    int i = 0;

    if (num == 0) {
        char c = n + '0';
        
        mx_printchar(c);
    }
    if (num < 0) {
        num *= -1;
        mx_printchar('-');
    }

    while (num != 0) {
        arr[i++] = (num % 10) + '0';
        num /= 10;
    }

    for (int j = i - 1; j >= 0; j--) {
        mx_printchar(arr[j]);
    }
}
