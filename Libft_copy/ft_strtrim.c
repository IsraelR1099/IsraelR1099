#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*new_str;
	int		lens1;
	int		position;

	new_str = (char *)s1;
	lens1 = ft_strlen((char *)s1) - 1;
	ptr = malloc(1 * lens1);
	if (ptr == NULL)
		return (0);
	while (lens1 >= 0 && ft_strchr((char *)set, new_str[lens1]) != NULL)
	{
		new_str[lens1] = '\0';
		lens1--;
	}
	position = 0;
	while (ft_strchr((char *)set, new_str[position]) != NULL)
	{
		new_str[position] = 't';
		position++;
	}
	return (new_str + position);
}
