#include "libft.h"
#include "tc.h"

int	main(void)
{
	char	s1[] = "papapaHello Worldapap";
	char	*pch;
	int	counter;
	int	lenS1;

	printf("%sarray original '%s'\n%s",TC_RED, s1, TC_NRM);
	lenS1 = ft_strlen(s1);
	pch = ft_strnstr(s1, "ab", lenS1); 
	printf("%sEl resultado es: %s\n%s", TC_GRN, ft_strtrim(s1, "pa"), TC_NRM);
	counter = 0;
	while (pch != NULL)
	{
		//printf("Found at %ld\n", pch - s1 + 1);
		counter++;
		pch = ft_strnstr(pch + 1, "ab", 10);
	}
	printf("Numero de veces %d\n", counter);

	return (0);
}
