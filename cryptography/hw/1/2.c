#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * shift_enc(int key, char * message);
char * shift_dec(int key, char * cipher);

int main()
{
    srand(time(0));
    int n = 3;
    int keys[n];
    for(int i = 0; i < n; ++i)
    {
        keys[i] = rand() % 26;
        printf("key[%d] = %d\n", i, keys[i]);
    }

    const char * message = "abc";
    char * ptr = shift_enc(*keys, (char *)message);
    for(int i = 1; i < n; ++i)
    {
        char * prev = ptr;
        ptr = shift_enc(keys[i], ptr);
        free(prev);
    }
    printf("encrypted ciphertext = %s\n", ptr);

    for(int key = 0; key < 26; ++key)
    {
        char * ret = shift_dec(key, (char *)ptr);
        printf("key = %d, %s\n", key, ret);
        free(ret);
    }
}