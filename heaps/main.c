#include <stdio.h>
#include <stdlib.h>

const char *s[] = { 
    "ar", 
    "bc", 
    "dc", 
    "ir" 
};

#define arr_len (int) ( sizeof s / sizeof (const char*) )

int arr_still_contain_item(int i, int len);

main() {
    int i = 0;
    while(arr_has_item(i,arr_len)) 
    {
        printf("%s\n", s[i]);
        i++;
    }
}

int arr_has_item(int i, int len)
{
    return i < len;
}
