#include "libft.h"
#include "tc.h"
#include <stdlib.h>
#include <malloc/malloc.h>
#include <string.h>
#include <stdio.h>

char	*i_to_a(int i);

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	int	number;
	int	len;
	char	*result;
	char	*res;
	char	*realit;
	char	*ptr = NULL;
	void	*p2;
	size_t	lenreal;
	int	comp;

	number = 10;
	lenreal = 2 + 1;
	p2 = malloc(lenreal);


	result = ft_itoa(number);
	res = ft_itoa(2147483647);
	realit = i_to_a(2147483647);
	comp = 	strcmp(realit, res);
	printf("%scomp es igual a '%d'\n%s", TC_RED, comp, TC_NRM);
	printf("%sEl resultado de result es '%s'\n%s", TC_GRN, result, TC_NRM);
	printf("%sEl resultado de res es '%s'\n%s", TC_GRN, res, TC_NRM);
	ft_print_result(res);
	
/*	printf("sizeof(result) = %zu\n", malloc_size(result));
	printf("sizeof(p2) = %zu\n", malloc_size(p2));
	
//	printf("sizeof(ptr) = %ld\n", malloc_usable_size(ptr));
//	free(ptr);
	free(result);
	len = 0;
	while (number /= 10)
	{
		printf("%d\n", number);
		len++;
	}
		printf("%d\n", len);
	
	int i = 0;
	unsigned int lastaddr = 0;
	while (i < 5)
	{
		//ptr = malloc(sizeof(char) * 2);
		printf("%d:%10p, size:%d\n", i++, result, (int)result - lastaddr);
		lastaddr = (int)result;
	}*/
	return (0);
}
