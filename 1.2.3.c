#include <stdio.h>

int main(void)
{
	unsigned short x, m, n;
	scanf("%hu%hu%hu", &x, &m, &n);
	if (m > 15)
	{
		fputs("m is out of range!\n", stderr);
		return 1;
	}
	if (n < 1 || n > 16 - m)
	{
		fputs("n is out of range!\n", stderr);
		return 1;
	}
	x &= (0xFFFF << m);
	x <<= 16 - n - m;
	printf("%X", x);
	return 0;
}