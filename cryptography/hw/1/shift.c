#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * shift_enc(int key, char * message)
{
    int n = strlen(message);
    char * ret = (char *)malloc((n + 1) * sizeof(char));
    for(int i = 0; i < n; ++i)
    {
        if('a' <= message[i] && message[i] <= 'z')
            ret[i] = (message[i] - 'a' + key) % 26 + 'a';
        else if('A' <= message[i] && message[i] <= 'Z')
            ret[i] = (message[i] - 'A' + key) % 26 + 'A';
        else
            ret[i] = message[i];
    }
    ret[n] = '\0';
    return ret;
}

char * shift_dec(int key, char * cipher)
{
    int n = strlen(cipher);
    char * ret = (char *)malloc((n + 1) * sizeof(char));
    for(int i = 0; i < n; ++i)
    {
        if('a' <= cipher[i] && cipher[i] <= 'z')
            ret[i] = ((cipher[i] - 'a' - key) % 26 + 26) % 26 + 'a';
        else if('A' <= cipher[i] && cipher[i] <= 'Z')
            ret[i] = ((cipher[i] - 'A' - key) % 26 + 26) % 26 + 'a';
        else
            ret[i] = cipher[i];
    }
    ret[n] = '\0';
    return ret;
}