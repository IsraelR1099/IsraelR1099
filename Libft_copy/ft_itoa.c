#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	nbr;

	len = ft_len(n);
	nbr = n;
	if (n < 0)
	{
		nbr = nbr * (-1);
		len++;
	}
	ptr = malloc(1 * (len + 1));
	if (!(ptr))
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	ptr[len + 1] = '\0';
	while (len--)
	{
		ptr[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
