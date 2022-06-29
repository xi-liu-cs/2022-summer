#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <gmp.h>
#include <gmpxx.h>
#define file FILE 
using namespace std;

/* convert a integer to string */
char * int_str(int a)
{
	int n_digit = log10(a) + 1,
	radix = 10; 
	char * res = (char *)malloc(n_digit * sizeof(char));
	sprintf(res, "%d", a);
	return res;
}

/* convert a file to binary string */
char * file_str(file * fp)
{
	string a; /* file content in original char */
	char c;
	while((c = fgetc(fp)) != -1)
		a += c;
	fclose(fp);
	
	int a_sz = a.size(),
	res_sz = 8 * a_sz + 1;
	char * res = (char *)malloc(res_sz * sizeof(char)); /* each char is 1 byte, represented by 8 bits */
	for(int i = 0; i < a_sz; ++i)
	{	
		char cur = a[i];
		for(int j = 0; j < 8; ++j)
		{
			res[8 * i + 7 - j] = '0' + (cur & 1);
			cur >>= 1;
		}
	}
	res[res_sz - 1] = '\0'; 
	return res;
}

/* pk = <q, g, g ^ x> 
   sk = <q, g, x> */
struct elgamal_key
{
	mpz_t q, g, x, gx;
};

void elgamal_key_gen(elgamal_key * res)
{
	#define q res->q
	#define g res->g
	#define x res->x
	#define gx res->gx

	time_t t;
	srand((unsigned)time(&t)); 
	mpz_init_set_str(q, int_str(rand() % (1 << 10)), 10);

	gmp_randstate_t state;
	gmp_randinit_default(state);

	mpz_init(g);
	mpz_urandomm(g, state, q);

	mpz_init(x);
	mpz_urandomm(x, state, q); /* rand int in [0, q - 1] */

	mpz_init(gx);
	mpz_pow_ui(gx, g, mpz_get_ui(x));
	gmp_printf("gx = %Zd\n", gx);

	#undef q
	#undef g
	#undef x
	#undef gx
}

void elgamal_encrypt
(
	mpz_t c1,
	mpz_t c2,
	mpz_t q,
	mpz_t g,
	mpz_t gx
)
{
	time_t t;
	srand((unsigned)time(&t)); 
	
	mpz_t y;
	mpz_init_set_str(y, int_str(rand() % (1 << 10)), 10);

	gmp_randstate_t state;
	gmp_randinit_default(state);

	mpz_init(y);
	mpz_urandomm(y, state, q);
}

int main()
{
	file * fp = fopen("t.txt", "r");
	printf("%s\n", file_str(fp));
	elgamal_key * res = (elgamal_key *)malloc(sizeof(elgamal_key));
	elgamal_key_gen(res);
	gmp_printf("gx = %Zd\n", res->gx);
}
