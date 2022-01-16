#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

int	main(void)
{
	//char	destination[5];
	//char	*source = "LARGE";
	char	destination2[5];
	char	*source2 = "LARGE";
	//int	result;
	int	result2;

	//result = strlcpy(destination, source, sizeof(destination));
	//printf("Con strlcpy resultado: %s y longitud %d\n", destination, result);

	result2 = ft_strlcpy(destination2, source2, sizeof(destination2));
	printf("Con ft_strlcpy resultado: %s y longitud %d\n", destination2, result2);

	return (0);
}


