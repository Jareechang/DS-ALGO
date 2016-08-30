#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int div_hash_num(int num, int bucket);
unsigned div_hash_str(char *s, int bucket);

int main(void)
{
    int rand_n = 1000;
    char s[] = "cat";
    printf("hash for %d: %d\n", rand_n, div_hash_num(rand_n, MAX));
    printf("hash for %s: %d\n", s, div_hash_str(s, MAX));
    return 0;
}

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
