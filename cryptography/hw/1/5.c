#include <stdio.h>
#include <math.h>

int main()
{
    for(int i = 0; i < 10; ++i)
        printf("5^%d = %f, 5^%d %% 7 = %d\n", i, pow(5, i), i, (int)pow(5, i) % 7);
}