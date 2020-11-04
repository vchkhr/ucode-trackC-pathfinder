#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *result = mx_strnew(1);

        result[0] = '0';

        return result;
    }

    if (nbr < 0) {
        return NULL;
    }

    char* hex_char[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
    unsigned long hex_num[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    unsigned long num = nbr;
    unsigned long counter = 0;

    while (num != 0) {
        long new_num = (unsigned long)(num / 16);

        num = new_num;
        counter++;
    }

    char *result = mx_strnew(counter);
    unsigned long iterator;
    unsigned long temp_i = counter - 1;

    num = nbr;

    while (num != 0) {
        unsigned long new_num = (unsigned long)(num / 16);
        unsigned long temp = (unsigned long)( num % 16);

        num = new_num;

        for (int i = 0; i < 16; i++) {
            if (hex_num[i] == temp) {
                iterator = i;
            }
        }
            
        result[temp_i] = *hex_char[iterator];
        temp_i--;
    }

    return result;
}
