#include <stdio.h>

int main ()
{
	unsigned char to_bit;
	int i;

	to_bit = 25;
	i = 8;
	while (i--)
	{
		if (to_bit >> i & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
