/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/12 13:01:49 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static void	ft_case(char **tmp, char **estr, int *result)
{
	if (**tmp == '|')
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
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str) + 1);
	exit (1);
}

int	fork1(void)
{
	int	pid;

	printf("entro en fork1\n");
	pid = fork();
	if (pid == -1)
		ft_error("fork");
	return (pid);
}

int	ft_find(char **pstr, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	if (*tmp && ft_strchr(tokens, *tmp))
		return (1);
	return (0);
}

int	gettoken(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		result;

	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	ft_case(&tmp, &estr, &result);
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (result);
}
