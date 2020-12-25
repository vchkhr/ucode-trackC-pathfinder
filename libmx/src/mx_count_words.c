#include "libmx.h"

int mx_count_words(const char *str, char c) {
    bool status = true;
    unsigned wordcount = 0;
    int i = 0;
    
    if (str == NULL)
        return -1;
        
    while (str[i]) {
        if (str[i] == c) {
            status = true;
        }
        else if (status == true) {
            status = false;
            ++wordcount;
        }
        
        ++i;
    }

    return wordcount;
}
