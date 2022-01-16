#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size);

int	main(void)
{
	char	first[] = "This is ";
	char	last[] = "a potentially long string";
	int	r;
	int	size = 16;
	char	buffer[size];

	strcpy(buffer, first);
	r = ft_strlcat(buffer, last, size);
	
	puts(buffer);
	printf("Value returned: %d\n", r);
		
	return (0);
}	

