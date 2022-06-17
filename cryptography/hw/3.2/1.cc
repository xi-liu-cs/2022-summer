#include <stdio.h>

/* kth step: find a quotient q_k, remainder r_k
r_{k - 2} = q_k * r_{k - 1} + r_k, r_k = r_{k - 2} % r_{k - 1} 
base step: k = 0, r_{k - 2} = r_{-2} = a, r_{k - 1} = r_{-1} = b 

gcd(a = 1071, b = 462)
step k:     equation                                            quotient, remainder
0           r_{-2} = 1071 = q_0 * (r_{-1} = 462) + r_0          q_0 = 2, r_0 = 147
1           r_{-1} = 462 = q_1 * (r_0 = 147) + r_1              q_1 = 3, r_1 = 21           
2           r_0 = 147 = q_2 * (r_1 = 21) + r_2                  q_2 = 7, r_2 = 0 */
   
int euclid_gcd(int a, int b)
{
    while(b)
    {
        int t = b;
        b = a % b; /* r_k = r_{k - 2} % r_{k - 1} */
        a = t; 
    }
    return a > -a ? a : -a;
}

int main()
{
    printf("%d\n", euclid_gcd(3, 6));
}
