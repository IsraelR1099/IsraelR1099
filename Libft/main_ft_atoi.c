#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(void)
{
	char	str[] = "122";
	int	x = atoi(str);
	printf("Converting '122': %d\n", x);

	char	str2[] = "Hello!";

	x = atoi(str2);
	printf("Converting 'Hello!': %d\n", x);

	char	str3[] = "99Hello";

	x = atoi(str3);
	printf("Converting '99Hello': %d\n", x);

	char	str4[] = " 99Hello";
	
	x = atoi(str4);
	printf("Converting ' 99Hello': %d\n", x);

	char	str5[] = "He99llo";
	char	str6[] = "12 34";


	x = atoi(str5);
	printf("Converting 'He99llo: %d\n", x);

	x = atoi(str6);
	printf("Converting '12 32': %d\n", x);
	

	return (0);
}

