#include <stdio.h>

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	position;
	int	len_dest;

	len_dest = 0;
	while (dest[len_dest] != '\0')
	{
		len_dest++;
	}

	position = 0;
	while (src[position] != '\0' && position < (size - 1))
	{
		dest[len_dest] = src[position];
		position++;
	}
	dest[len_dest + position] = '\0';

	return (len_dest + position);
}

