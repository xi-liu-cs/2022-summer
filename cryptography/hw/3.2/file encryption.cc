#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <gmp.h>
#include <gmpxx.h>
#define file FILE 
using namespace std;

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


struct pk
{
	mpz_t q, g, gx; /* g ^ x */
};

struct sk
{	
	mpz_t q, g, x;
};

struct key
{
	pk pub_key;
	sk sec_key;
};

void key_gen()
{
	//#define q res.q
	//#define g res.g
	//#define gx res.gx
	gmp_randstate_t state;
	gmp_randinit_default(state);
	time_t t;
       	srand((unsigned)time(&t)); 
	
	mpz_t q;
	mpz_init_set_str(q, int_str(rand() % (1 << 10)), 10);
	
	mpz_t g;
	mpz_init(g);
	mpz_urandomm(g, state, q);
	
	mpz_t x;
	mpz_init(x);
	mpz_urandomm(x, state, q); /* rand int in [0, q - 1] */

	mpz_t gx;
	mpz_init(gx);
	mpz_pow_ui(gx, g, mpz_get_ui(x));
	gmp_printf("%Zd\n", gx);
}

int main()
{
	file * fp = fopen("t.txt", "r");
	printf("%s\n", file_str(fp));
	key_gen();
	//key * k = key_gen();
	//gmp_printf("%Zd\n", *((k->pub_key).gx));
}
