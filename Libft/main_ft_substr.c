#include "libft.h"

int	main(void)
{
	char	*p = ft_substr("Jose Perez", 0, 4);
	char	*test = NULL;

	printf("El resultado es: %s\n", p);
	
	int i = 0;
	unsigned int lastaddr = 0;
	while ( i < 1)
	{
		printf("%d:%10p, size:%d\n", i++, p, (int)p - lastaddr);
		lastaddr = (int)p;
	}
	i = 0;
	lastaddr = 0;
	while (i < 1)
	{
		test = (char *)malloc(sizeof(char) * 2);
		printf("%d:%10p, size:%d\n", i++, test, (int)test - lastaddr);
		lastaddr = (int)test;
	}
	free(test);
	free(p);	

	return (0);
}
