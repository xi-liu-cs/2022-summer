#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

char * int_str(int a)
{
	int n_digit = log10(a) + 1,
	radix = 10; 
	char * res = (char *)malloc(n_digit * sizeof(char));
	sprintf(res, "%d", a);
	return res;
}

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
	int p = 1013,
	q = 1019,
	n = p * q;
	printf("n: %d\n", n);
	int e = 2;
	/* phi(i): number of integers less than i that do not share a common factor with i
	since prime numbers have no factors greater than 1, so the i - 1 positive integers
	do not share a common factor with i
	if(is_prime(i))
		phi(i) = i - 1

	phi(pq) = phi(p) * phi(q) = (p - 1) * (q - 1)
	p, q are prime factors of pq, integer k is coprime to pq iff it is not a
	multiple of p or q. in 0 < k < pq, there are p - 1 multiples of q
	q - 1 multiples of p, so (p - 1) + (q - 1) integers share a factor with pq
	phi(pq) = (#integers < pq) - (#integers not coprime)
		= (pq - 1) - ((p - 1) + (q - 1))
		= pq - 1 - p - q + 2
		= pq - p - q + 1
		= (p - 1)(q - 1) */
	int phi = (p - 1) * (q - 1);

	/* choose encrypt e:
	1 < e < phi(n)
	coprime with n, phi(n) */
	while(e < phi)
	{
		if(euclid_gcd(e, phi) == 1)
			break;
		else
			++e;
	}
	printf("e: %d\n", e);

	/* choose decrypt d:
	de = 1  mod phi(n) 

	m ^ e = c  mod n
	c ^ d = m  mod n
	(m ^ e) ^ d = m  mod n
	m ^ {ed} = m  mod n

	euler's theorem
	m ^ {phi(n)} = 1  mod n
	1 ^ i = 1
	m ^ {i * phi(n)} = 1  mod n
	m * m ^ {i * phi(n)} = m  mod n
	m ^ {i * phi(n) + 1} = m  mod n

	since m ^ {ed} = m  mod n
	ed = i * phi(n) + 1
	d = (i * phi(n) + 1) / e
	easy to calcuate d iff factorization of n is known */
	int i = 2,
	d = (i * phi + 1) / e,
	msg = 12;
	printf("d: %d\n", d);
	printf("msg: %d\n", msg);

	/* encryption: c = (msg ^ e) % n */
	char * msg_str = int_str(msg),
	* e_str = int_str(e),
	* n_str = int_str(n);
	mpz_t _msg, _e, _n, c; 
	mpz_init_set_str(_msg, msg_str, 10);
	mpz_init_set_str(_e, e_str, 10);
	mpz_init_set_str(_n, n_str, 10);
	mpz_init(c);
	mpz_powm(c, _msg, _e, _n);
	gmp_printf("ciphertext: %Zd\n", c);

	/* decryption: m = (c ^ d) % n */
	char * d_str = int_str(d);
	mpz_t _d, m;
	mpz_init_set_str(_d, d_str, 10);
	mpz_init(m);
	mpz_powm(m, c, _d, _n);
	gmp_printf("original msg: %Zd\n", m);
}
