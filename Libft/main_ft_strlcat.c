#include "libft.h"
#include <string.h>
#include "tc.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size);

int	main(void)
{
	char	first2[] = "This is ";
	char	first[] = "This is ";
	char	last[] = "a potentially long string";
	char	last2[] = "a potentially long string";
	char	dest[30]; ft_memset(dest, 0, 30);
	//char	*src = (char *)"AAAAAAAAA";
	int	r;
	int	t;
	int	size = 16;
	int	size2 = 16;
	char	buffer[size];
	char	buffer2[size2];
	char	test[] = "27";
	char	test1[] = "rrrrrra";
	int	p;
	int	len1;
	int	len2;

	strcpy(buffer, first);
	r = ft_strlcat(buffer, last, size);

	strcpy(buffer2, first2);
	t = strlcat(buffer2, last2, size2);
	
	len1 = ft_strlen(test);
	len2 = ft_strlen(test1);
	p = ft_strlcat(test, test1, 10);

	printf("len test '%d'  y len test1 '%d'\n", len1, len2);	
	printf("%sLa cadena es '%s' y longitud '%d'\n%s", TC_GRN, test, p, TC_NRM);

	dest[0] = 'B';
	ft_memset(dest, 0, 30);
	p = ft_strlcat(dest, "123", 2);
	printf("%sLa cadena es '%s' y longitud '%d'\n%s", TC_GRN, dest, p, TC_NRM);


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

