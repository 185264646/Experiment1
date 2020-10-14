#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int ch;
	while((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			putchar(tolower(ch));
		else
			putchar(ch);
	}
	return 0;
}