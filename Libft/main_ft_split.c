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
	char	str[] = "hola que tal estas todo bien";
	char	delim = ' ';
	int	len;
//	char	*ptr;

	printf("%sLa string completa es '%s'\n%s", TC_RED, str, TC_NRM);
/*	while (ptr != NULL)
	{
		printf("%sFound at %ld\n%s", TC_GRN, ptr - str + 1, TC_NRM);
		ptr = ft_strnstr(ptr + 1, delim, 20);
	}*/
	int	i = 0;
	int	cnter = 0;

	len = ft_strlen(str);
	printf("len es '%d'\n", len);
	while (str[i] == delim)
		i++;
	char *pch = ft_strchr(str + i, delim);
	while (str[i])
	{
		while (str[i] == delim)
			i++;
		if (pch != NULL)
		{
			pch = ft_strchr(pch + 1, delim);
			cnter++;
		}
		while (str[i] && (ft_strncmp(str + i, (const char *)delim, len)))
					i++;
	}
		printf("Counter es %d\n", cnter);
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
		printf("Counter es %d\n", cnter);
	}
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
