#include "libft.h"
#include "tc.h"

/*char	*foo(char *str, char *c)
{
	static char	*buffer;
	char		*token;

	*buffer = NULL;
	if (!c)
		return NULL;
	if (!buffer)
		buffer = str;
	if (!*buffer)
		return NULL;
	*token = buffer;
	while (*buffer && *buffer != c)
	{
		buffer += 1;
	}

	return (token);

}*/

int	main(void)
{
	char	*str = " hola que tal estas";
//	char	delim = ' ';
	char	**ptr;

	ptr = &str;
//	printf("ptr es %s\n", *ptr);
	ptr = ft_split("   hola como estas todo bien", ' ');

//	printf("el resultado es %s\n", test[0]);
	printf("%sresultado ptr 0 es '%s'\n%s", TC_GRN, ptr[0], TC_NRM);
	printf("%sresultado ptr 1 es '%s'\n%s", TC_GRN, ptr[1], TC_NRM);
	printf("%sresultado ptr 2 es '%s'\n%s", TC_GRN, ptr[2], TC_NRM);
	printf("%sresultado ptr 3 es '%s'\n%s", TC_GRN, ptr[3], TC_NRM);
	printf("%sresultado ptr 4 es '%s'\n%s", TC_GRN, ptr[4], TC_NRM);

	return (0);
}
