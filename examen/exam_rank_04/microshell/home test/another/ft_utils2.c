/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:55:34 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/31 13:32:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)dst;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}

int	ft_fork1(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("panic fork", 1);
	return (pid);
}

void	ft_error(const char *str, int value)
{
	if (write(2, str, ft_strlen(str)) < 0)
		exit (-1);
	exit (value);
}

int	ft_find(char **pstr, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\n\r\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (*tmp && ft_strchr(tokens, *tmp));
}

int	ft_gettoken(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\n\r\v ", *tmp))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	ret = *tmp;
	if (*tmp == 0)
		return (0);
	else if (*tmp == '|')
		tmp++;
	else if (*tmp == ';')
		tmp++;
	else
	{
		ret = 'a';
		while (tmp < estr && !ft_strchr("\t\n\r\v ", *tmp)
				&& !ft_strchr("|;", *tmp))
			tmp++;
	}
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\n\r\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (ret);
}
