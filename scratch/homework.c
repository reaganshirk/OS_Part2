#include <stdio.h>

enum classesMask
{
	OS = 		1 << 0,
	POPL =		1 << 1,
	THEORY =	1 << 2,
	HONRSC = 	1 << 3,
	OSTHEORY = 	1 << 4,
	AI = 		1 << 5,
	GRAPHICS = 	1 << 6,
	HCI = 		1 << 7,
	COMPILERS = 	1 << 8
};

typedef struct _student student;
struct _student
{
	char* name;
	int enrolledClasses;
};

int main(int argc, char** argv)
{
	int b = 0x0;
	b |= OSTHEORY | HONRSC | COMPILERS | HCI | GRAPHICS;
	b &= ~OSTHEORY;
	b |= OS;

	if (b & (GRAPHICS | HCI))
	{
		b &= ~GRAPHICS;
	}
	if (b & (COMPILERS & ~POPL))
	{
		b &= ~THEORY;
	}

	printf("%x\n", b);
	return 0;
}
