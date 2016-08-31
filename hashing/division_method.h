#include <stdio.h>

int div_hash_num(int num, int bucket)
{
    return num % (bucket);
}

unsigned div_hash_str(char *s, int bucket)
{
    unsigned val;
    while(*s != '\0') {
        val = (*s++) + 31 * val;
    }
    return val % bucket;
}
