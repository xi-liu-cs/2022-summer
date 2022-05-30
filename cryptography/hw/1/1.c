#include <stdio.h>
#include <stdlib.h>

char * shift_dec(int key, char * cipher);

int main()
{
    const char * s = "ibbiks eqbp nctt nwzkm ia awwv ia bpm acv zqama";
    for(int key = 1; key < 10; ++key)
    {
        char * ret = shift_dec(key, (char *)s);
        printf("key = %d, %s\n", key, ret);
        free(ret);
    }
}