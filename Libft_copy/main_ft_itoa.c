#include "libft.h"
#include "tc.h"

int	main(void)
{
	int	number;
	int	len;
	char	*result;

	number = -2147483648;

	result = ft_itoa(number);
	printf("%sEl resultado es %s\n%s", TC_GRN, result, TC_NRM);
	len = 0;
	while (number /= 10)
	{
		printf("%d\n", number);
		len++;
	}
		printf("%d\n", len);

	return (0);
}
