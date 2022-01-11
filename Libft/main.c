/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:30:14 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/11 17:30:49 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_strlen(char *str);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strchr(char *str, int ch);
char	*ft_strrchr(char *str, int ch);
int	ft_strncmp(const char *str1, const char *str2, unsigned int number);

int	main(void)
{
	char c;

	c = 'Q';
	printf("Uppercase alphabet: %d", ft_isalpha(c));

	c = 'q';
	printf("\nLowercase alphabet: %d", ft_isalpha(c));

	c = '+';
	printf("\nNon-alphabtic character: %d", ft_isalpha(c));

	c = 32;
	printf("\nNumber: %d", ft_isalpha(c));

	c = '/';
	printf("\nCase: %d", ft_isalpha(c));

	c = 0;
	printf("\nIt is a number: %d", ft_isdigit(c));

	c = 'a';
	printf("\nIt is not a number: %d", ft_isdigit(c));
	
	c = 'S';
	printf("\nAlphanumeric character: %d", ft_isalnum(c));

	c = 6;
	printf("\nAlphanumeric character: %d", ft_isalnum(c));

	c = ':';
	printf("\nIt is not alphanumeric character: %d", ft_isalnum(c));
	
	c = ':';
	printf ("\nIt is ascii: %d", ft_isascii(c));

	c ='&';
	printf("\nIt is printable: %d", ft_isprint(c));

	c = '\n';
	printf("\nIt is not printable: %d", ft_isprint(c));

	char	str2[20] = "hola";
	printf("\nLenght of str is: %d", ft_strlen(str2));

	c = 'z';
	printf("\nUpper case: %c", ft_toupper(c));

	c = '9';
	printf("\nSame case: %c", ft_toupper(c));

	c = 'Z';
	printf("\nLower case: %c", ft_tolower(c));

	c = '&';
	printf("\nSame case: %c", ft_tolower(c));

	char test[] = "This is easy";
	c = 'p';
	if (ft_strchr(test, c))
	printf("\n%c is present", c);
	else
		printf("\n%c is not present", c);

	char	test2[] = "Hello Worlod";
	char *pch;
	
	c = 'o';

	pch = ft_strrchr(test2, 'o');
	printf("\nLa ultima letra de %c encontrado en %ld", c, pch - test2+1);

	char	str1[] = "HelLo";
	char	str3[] = "Hello";

	printf("\nSon iguales hasta %d", ft_strncmp(str1, str3, 4));


	return (0);
}
