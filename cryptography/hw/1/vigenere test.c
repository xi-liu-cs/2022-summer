#include <stdio.h>

char * vigenere_enc(char * s, char * message);
char * vigenere_dec(char * s, char * cipher);

int main()
{
    char * m = "wxyz",
    * s = "ab",
    * enc = vigenere_enc(s, m),
    * dec = vigenere_dec(s, enc);
    printf("enc = %s\ndec = %s\n", enc, dec);
}