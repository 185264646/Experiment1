#include <stdio.h>
#include <string.h>
#pragma pack (1)

// Rotate union ch x according to rule.
#define ROL(x) for(int i=0, temp; i < x->hi2; i++)\
{\
	temp = x->r0;\
	x->r0 = x->r5;\
	x->r5 = x->r4;\
	x->r4 = x->r3;\
	x->r3 = x->r2;\
	x->r2 = x->r1;\
	x->r1 = temp;\
}
	

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
	int temp, i;
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
	
	ROL(ch);
}
