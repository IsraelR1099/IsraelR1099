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
	char	str[] = "hola que tal estas";
	char	delim = ' ';
	int	len;
	char	**tab;

	printf("%sLa string completa es '%s'\n%s", TC_RED, str, TC_NRM);
	int	i = 0;
	int	cnter = 0;
	tab = ft_split(str, delim);
	printf("La nueva string es %s\n", (char *)tab);

	len = ft_strlen(str);
	printf("len es '%d'\n", len);
	char *buffer;
	buffer = str;
	while (*buffer)
	{
		while (*buffer == delim)
			buffer += 1;
		if (*buffer)
		{
			cnter++;
		}
		while (*buffer && !(*buffer == delim))
					buffer += 1;
	}
		printf("%sCounter 1 es %d\n%s", TC_GRN, cnter, TC_NRM);
	i = 0;
	cnter = 0;
	while (str[i])
	{
		while (str[i] == delim)
			i++;
		if (str[i] != '\0')
			cnter++;
		while (str[i] && str[i] != delim)
			i++;
	}
		printf("%sCounter 2 es %d\n%s", TC_GRN, cnter, TC_NRM);
	i = 0;
	int num_words = 0;

	if (str[0] != delim)
	{
		num_words = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != delim && str[i - 1] == delim)
			num_words++;
		i++;
	}
		printf("Num words es %d\n", num_words);
	return (0);
}
