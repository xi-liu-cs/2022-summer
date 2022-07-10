#include <stdio.h>
#define n 64
#define b(x) (1ull << (x))
#define rot_left(a, i, n) (a << i | a >> (n - i))
#define print(i, n)\
{\
	for (i = n; --i; i)\
	    putchar(st & b(i) ? '#' : '.');\
	putchar('\n');\    
}
typedef unsigned long long ull;
 
void evolve(ull state, int rule)
{
	int i;
	ull st;
 
	printf("rule %d:\n", rule);
	do 
	{
		st = state;
		for(i = n; --i; i) 
		    putchar(st & b(i) ? '#' : '.');
		putchar('\n');
 
		for(state = i = 0; i < n; ++i)
			if(rule & b(7 & rot_left(st, i, n)))
				state |= b(i);
	}while (st != state);
}
 
int main(int argc, char ** argv)
{
	evolve(b(n / 2), 90);
	evolve(b(n / 4) | b(n - n / 4), 30);
}
