#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(void)
{
	char	str[] = "122";
	char	hola[] = "122";
	int	x = atoi(str);
	int	resultado;

	resultado = ft_atoi(hola);
	printf("\033[31;1;13mConverting '%s': %d\n\033[0m",str, x);
	printf("\033[32;1;13mConverting '%s' with ft_atoi: %d\n\033[0m", hola, resultado);

	char	str2[] = "Hello!";
	char	hola2[] = "Hello!";

	resultado = ft_atoi(hola2);
	x = atoi(str2);
	printf("\033[31;1;13mConverting 'Hello!': %d\n\033[0m", x);
	printf("\033[32;1;13mConverting with ft_atoi '%s': %d\n\033[0m", hola2, resultado);

	char	str3[] = "\t+99Hello";
	char	hola3[] = "\t+99Hello";

	x = atoi(str3);
	resultado = ft_atoi(hola3);
	printf("\033[31;1;13mConverting '%s': %d\n\033[0m", str3, x);
	printf("\033[32;1;13mConverting with ft_atoi '%s': %d\n\033[0m", hola3, resultado);

	char	str4[] = " 99Hello";
	char	hola4[] = " 99Hello";
	
	x = atoi(str4);
	resultado = ft_atoi(hola4);
	printf("\033[31;1;13mConverting '\t99Hello': %d\n\033[0m", x);
	printf("\033[32;1;13mConverting with ft_atoi '%s': %d\n\033[0m", hola4, resultado);

	char	str5[] = "He99llo";
	char	str6[] = "12 34";
	char	hola6[] = "12 34";
	char	hola5[] = "He99llo";

	x = atoi(str5);
	resultado = ft_atoi(hola5);
	printf("\033[31;1;13mConverting 'He99llo: %d\n\033[0m", x);
	printf("\033[32;1;13mConverting with ft_atoi '%s': %d\n\033[0m", hola5, resultado);

	x = atoi(str6);
	resultado = ft_atoi(hola6);
	printf("\033[31;1;13mConverting '12 32': %d\n\033[0m", x);
	printf("\033[32;1;13mConverting with ft_atoi '%s': %d\n\033[0m", hola6, resultado);
	
	char	str7[] = "2147483647";
	char	hola7[] = "2147483647";
	
	x = atoi(str7);
	resultado = ft_atoi(hola7);

	printf("\033[31;1;13mConverting INT_MAX '%s': %d\n\033[0m", str7, x);
	printf("\033[32;1;13mConverting INT_MAX with ft_atoi '%s': %d\n\033[0m", hola7, resultado);

	char	str8[] = "-2147483648";
	char	hola8[] = "-2147483648";

	x = atoi(str8);
	resultado = ft_atoi(hola8);

	printf("\033[31;1;13mConverting INT_MIN '%s': %d\n\033[0m", str8, x);
	printf("\033[32;1;13mConverting INT_MIN with ft_atoi '%s': %d\n\033[0m", hola8, resultado);

	return (0);
}

