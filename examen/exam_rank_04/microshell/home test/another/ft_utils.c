/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:57:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/28 17:34:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)dst;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	const char *ptr;

	if (!str)
		return (0);
	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)str + i);
	return (0);
}

void	ft_error(const char *str, char *ptr)
{
	if (write(2, str, ft_strlen(str)) < 0)
		exit(-1);
	exit(-1);
}

int	ft_fork1(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		return (0);
	return (pid);
}

int ft_find(char **ptr, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *ptr;
	while (tmp < estr && ft_strchr("\t\n\r\v ", *tmp))
		tmp++;
	*ptr = tmp;
	return (*tmp && ft_strchr(tokens, *tmp));
}

int ft_gettonken(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		result;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\n\r\v ", *tmp))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	result = *tmp;
	if (*tmp == 0)
		return (0);
	else if (*tmp == '|')
		tmp++;
	else if (*tmp == ';')
		tmp++;
	else
	{
		result = 'a';
		while (tmp < estr && !ft_strchr("\t\n\r\v ", *tmp) &&
			!ft_strchr("|;", *tmp))
			tmp++;
	}
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\n\r\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (result);
}
