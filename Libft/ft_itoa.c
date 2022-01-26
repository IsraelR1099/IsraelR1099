#include "libft.h"

char	*ft_itoa(int n)
{
	int	len;
	int	sign;
	int	nbr;

	ptr = malloc(1 * (len + 1));

	if (!(ptr))
		return NULL;
	position = 0;
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		*ptr = '-';
		nbr = n * -1;
	}
	else

	



