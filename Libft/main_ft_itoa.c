#include "libft.h"
#include "tc.h"

int	main(void)
{
	int	number;
	int	len;
	int	number2;
	char	*result;
	char	*result2;

	number = 2147483647;
	number2 = 0;
	result = ft_itoa(number);
	result2 = ft_itoa(1561225);
	printf("%sEl resultado es %s\n%s", TC_GRN, result, TC_NRM);
	printf("%sEl resultado es %s\n%s", TC_GRN, result2, TC_NRM);

	len = 0;
	while (number /= 10)
	{
		printf("%d\n", number);
		len++;
	}
		printf("%d\n", len);
	
	int	len2 = 0;
	int	n;

	n = 1;
	while (n)
	{
		n /= 10;
		len2++;
	}
	printf("%sLen es igual a %d\n%s", TC_GRN, len2, TC_NRM);

	return (0);
}
