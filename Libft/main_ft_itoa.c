#include "libft.h"
#include "tc.h"
#include <malloc.h>

int	main(void)
{
	int	number;
	int	len;
	char	*result;
	char	*ptr = NULL;

	number = -2147483648;

	result = ft_itoa(number);
	printf("%sEl resultado es %s\n%s", TC_GRN, result, TC_NRM);
	printf("sizeof(result) = %ld\n", malloc_usable_size(result));
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
	}

	return (0);
}
