#include <stdio.h>
#include <string.h>
#pragma pack (1)

// make x Rotate Left b bits
#define ROL(x, b) for(int i=0; i<(b); i++) x % 2 ? (((x)=(x)<<1)|1) : ((x)<<=1)

union ch {
	char orig;
	struct {
		unsigned char lo6:6;
		unsigned char hi2:2;
	};
	struct {
		unsigned char r0:1;
		unsigned char r1:1;
		unsigned char r2:1;
		unsigned char r3:1;
		unsigned char r4:1;
		unsigned char r5:1;
		unsigned char :2;
	};
};

void encrypt(union ch *);
int main(void)
{
	union ch ch[BUFSIZ];
	int len, i;
	gets((char *)ch);
	len = strlen(&ch->orig);
	for (i = 0; i < len; i++)
		encrypt(&ch[i]);
	puts(&ch->orig);
	return 0;
}

void encrypt(union ch *ch)
{
	int temp;
	// Swap bit0 and bit1
	temp = ch->r0;
	ch->r0 = ch->r1;
	ch->r1 = temp;
	
	// Swap bit2 and bit3
	temp = ch->r2;
	ch->r2 = ch->r3;
	ch->r3 = temp;
	
	// Swap bit4 and bit5
	temp = ch->r4;
	ch->r4 = ch->r5;
	ch->r5 = temp;
	 
	ROL(ch->lo6, ch->hi2);
}
