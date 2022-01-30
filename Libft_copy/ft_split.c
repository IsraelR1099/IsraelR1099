#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int	position;
	char	*ptr;
	char	**split;
	int	start;

	ptr = malloc(1 * ft_strlen((char *)s));
	position = 0;
	start = 1;
	while ((char *)s[position] != '\0')
	{
		if ((char *)s[position] == c)
		{
			split = ft_substr(s, start, position);
			split[position] = '\0';
			return (split);
		}
		position++;
	}

}
