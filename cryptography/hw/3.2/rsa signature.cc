#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

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

/* (left1, left2) = (right1, right2) */
#define parallel_assign(left1, left2, right1, right2)\
{\
    int tmp = right1;\
    left2 = right2;\
    left1 = tmp;\
}

/* return x and y s.t. ax + by = gcd(a, b) 
r is remainder 
return value: (*ret, ret[1]) = (x, y)
ret[2] = gcd(a, b) */
int * extend_euclid_gcd(int a, int b)
{
    int old_r = a, r = b,
    old_s = 1, s = 0,
    old_t = 0, t = 1;
    while(r)
    {
        int quotient = old_r / r;
        parallel_assign(old_r, r, r, old_r - quotient * r);
        parallel_assign(old_s, s, s, old_s - quotient * s);
        parallel_assign(old_t, t, t, old_t - quotient * t);
    }
    int * ret = (int *)malloc(3 * sizeof(int));
    *ret = old_s, ret[1] = old_t, ret[2] = old_r;
    return ret;
}

int main()
{
    int p = 8,
    q = 9,
    n = p * q,
    _n = (p - 1) * (q - 1);
    
    vector<int> key;
    for(int i = 2; i < _n; ++i)
    {
        int gcd = euclid_gcd(_n, i);
        if(gcd == 1)
            key.push_back(i);
    }
    
    int enc = 3, dec;
    int * ext_gcd = extend_euclid_gcd(_n, enc);
    if(ext_gcd[2] == 1)
    {
        dec = ext_gcd[1];
        printf("decryption key is %d\n", dec);
    }
    else
        printf("no multiplicative inverse for given encryption key\n");
    int msg = 2, /* message */
    sig = (int)pow(msg, dec) % n, /* signature */
    msg_gen = (int)pow(sig, enc) % n; /* generated message */
    printf("sig = %d\n", sig);
    printf("n = %d\n", n);
    printf("msg_gen = %d\n", msg_gen);
    if(msg == msg_gen)
        printf("accept\n");
    else
        printf("reject\n");
}
