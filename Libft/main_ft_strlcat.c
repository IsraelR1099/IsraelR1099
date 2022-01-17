#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size);

int	main(void)
{
	char	first2[] = "This is ";
	char	first[] = "This is ";
	char	last[] = "a potentially long string";
	char	last2[] = "a potentially long string";
	int	r;
	int	t;
	int	size = 16;
	int	size2 = 16;
	char	buffer[size];
	char	buffer2[size2];

	strcpy(buffer, first);
	r = ft_strlcat(buffer, last, size);

	strcpy(buffer2, first2);
	t = strlcat(buffer2, last2, size2);
	
	printf("\033[31;1;13mCon strlcat resultado: '%s' y longitud %d\n\033[0m", buffer2, t);
	if (t > size)
		printf("La cadena ha sido truncada\n");
	else
		printf("La cadena fue copiada completamente\n");
	printf("\033[32;1;13mCon ft_strlcat resultado: '%s' y longitud %d\n\033[0m", buffer, r);
	if (r > size)
		printf("La cadena ha sido truncada\n");
	else
		printf("La cadena fue copiada completamente\n");

		
	return (0);
}	

