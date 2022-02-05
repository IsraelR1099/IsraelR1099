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
	char	delim = ' ';
	char	**test;
   
	test = ft_split(str, delim);


	printf("el resultado es %s\n", test[0]);

	return (0);
}
