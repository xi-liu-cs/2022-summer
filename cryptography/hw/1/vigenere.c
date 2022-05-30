#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * vigenere_enc(char * s, char * message)
{
    int s_len = strlen(s), m_len = strlen(message);
    char * ret = (char *)malloc((m_len + 1) * sizeof(char));
    for(int i = 0; i < m_len; ++i)
    {
        if('a' <= message[i] && message[i] <= 'z')
            ret[i] = (message[i] - 'a' + (s[i % s_len] - 'a' + 1)) % 26 + 'a';
        else if('A' <= message[i] && message[i] <= 'Z')
            ret[i] = (message[i] - 'a' + (s[i % s_len] - 'A' + 1)) % 26 + 'A';
        else 
            ret[i] = message[i];
    }
    ret[m_len] = '\0';
    return ret;
}

char * vigenere_dec(char * s, char * cipher)
{
    int s_len = strlen(s), c_len = strlen(cipher);
    char * ret = (char *)malloc((c_len + 1) * sizeof(char));
    for(int i = 0; i < c_len; ++i)
    {
        if('a' <= cipher[i] && cipher[i] <= 'z')
            ret[i] = ((cipher[i] - 'a' - (s[i % s_len] - 'a' + 1)) % 26 + 26) % 26 + 'a';
        else if('A' <= cipher[i] && cipher[i] <= 'Z')
            ret[i] = ((cipher[i] - 'a' - (s[i % s_len] - 'A' + 1)) % 26 + 26) % 26 + 'A';
        else 
            ret[i] = cipher[i];
    }
    ret[c_len] = '\0';
    return ret;
} 