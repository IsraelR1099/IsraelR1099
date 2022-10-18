/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/17 21:50:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

/*static void	ft_case(char **tmp, char **estr, int *result)
{
	if (**tmp == 0)
		return ;
	else if (**tmp == '|')
		*tmp = *tmp + 1;
	else if (**tmp == '<')
		*tmp = *tmp + 1;
	else if (**tmp == '>')
	{
		*tmp = *tmp + 1;
		if (**tmp == '>')
		{
			*result = '+';
			*tmp = *tmp + 1;
		}
	}
	else
	{
		*result = 'z';
		while (*tmp < *estr && !ft_strchr("\t\r\n\v ", **tmp)
			&& !ft_strchr("<|>", **tmp))
			*tmp = *tmp + 1;
	}
}*/

void	ft_error(char *str, int exit_code)
{
	write(2, str, ft_strlen(str) + 1);
	exit((unsigned char)exit_code);
}

int	fork1(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork", 1);
	return (pid);
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

int	gettoken(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char		*tmp;
	int			result;

	tmp = *pstr;
	if (*tmp == 34 || *tmp == 39)
	{
		if (*tmp == 34)
			ft_quotes(pstr, estr, ftoken, eftoken);
		else if (*tmp == 39)
			ft_quotes_simple(pstr, estr, ftoken, eftoken);
		result = 'z';
		return (result);
	}
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	result = *tmp;
	if (*tmp == 0)
		return (0);
	else if (*tmp == '|')
		tmp = tmp + 1;
	else if (*tmp == '<')
	{
		tmp = tmp + 1;
		if (*tmp == '<')
		{
			result = '-';
			tmp = tmp + 1;
		}
	}
	else if (*tmp == '>')
	{
		tmp = tmp + 1;
		if (*tmp == '>')
		{
			result = '+';
			tmp = tmp + 1;
		}
	}
	else
	{
		result = 'z';
		while (tmp < estr && !ft_strchr("\t\r\n\v\" ", *tmp)
			&& !ft_strchr("<|>", *tmp))
			tmp = tmp + 1;
	}
//	ft_case(&tmp, &estr, &result);
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (result);
}
