#include <stdio.h>
#include<string.h>
void encrypt(char *c);
inline void encrypt(char *c)
{
	_Bool bit = *c & 0x40;
	*c = ((*c >> 1 & 0x15) | (*c << 1 & 0x2A)) & 0x3F;
	if (bit)
	{
		bit = *c & 0x20;
		*c = (*c << 1) | 0x40 | bit;
	}
	return;
}

int main(void)
{
	char a[BUFSIZ];
	int i, len;
	fgets(a, BUFSIZ, stdin);
	a[strlen(a) - 1] = '\0';
	len = strlen(a);
	for (i = 0; i < len; i++)
		encrypt(a + i);
	puts(a);
	return 0;
}
