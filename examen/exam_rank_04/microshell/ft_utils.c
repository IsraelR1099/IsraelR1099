/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:45:16 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/19 13:48:05 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	unsigned int	i;
	char			*new_dest;

	new_dest = (char *)dest;
	i = 0;
	while (i < count)
	{
		new_dest[i] = (char)ch;
		i++;
	}
	return (new_dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_error(const char *str, size_t value)
{
	if (write(2, str, ft_strlen(str)) < 0)
		exit (-1);
	exit(value);
}

int	ft_fork1(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork error", 1);
	return (pid);
}

char	*ft_strchr(const char *str, int ch)
{
	int	position;

	position = 0;
	while(str[position] != '\0')
	{
		if (str[position] == (char)ch)
			return ((char *)str + position);
		position++;
	}
	if (str[position] == (char)ch)
		return ((char *)str + position);
	return (0);
}

int	ft_find(char **pstr, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (*tmp && ft_strchr(tokens, *tmp));
}

int	ft_gettoken(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		result;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
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
		result = 'z';
		while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
			tmp++;
	}
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (result);
}
