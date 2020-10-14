#include <stdio.h>
union ip{
	unsigned long i;
	unsigned char ch[4];
};
	
int main(void)
{
	union ip n;
	while(scanf("%lu", &n.i) != EOF)
		printf("%hhu.%hhu.%hhu.%hhu\n", n.ch[3], n.ch[2], n.ch[1], n.ch[0]);
	return 0;
}
	