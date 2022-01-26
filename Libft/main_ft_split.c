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
	char	str[] = "Needs to be called, several, times to split";
	char	delim[] = " ";
	char	*ptr;

	printf("%sLa string completa es '%s'\n%s", TC_RED, str, TC_NRM);
	ptr = ft_strnstr(str, delim, 20);
	while (ptr != NULL)
	{
		printf("%sFound at %ld\n%s", TC_GRN, ptr - str + 1, TC_NRM);
		ptr = ft_strnstr(ptr + 1, delim, 20);
	}
	return (0);
}
