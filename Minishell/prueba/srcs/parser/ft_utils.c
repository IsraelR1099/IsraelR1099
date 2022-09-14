/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/14 14:18:40 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static void	ft_case(char **tmp, char **estr, int *result)
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
}

void	ft_error(char *str, int exit_code)
{
	write(2, str, ft_strlen(str) + 1);
	exit ((unsigned char)exit_code);
}

int	fork1(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork");
	return (pid);
}

int	ft_find(char **pstr, char *estr, char *tokens)
{
	char	*tmp;

	printf("entro en ft find\n");
	tmp = *pstr;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	/*if (*tmp && ft_strchr(tokens, *tmp))
		return (1);
	printf("retorno 0\n");
	return (0);*/
	printf("retorno %d\n", (*tmp && ft_strchr(tokens, *tmp)));
	return (*tmp && ft_strchr(tokens, *tmp));
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
	result = *tmp;
	ft_case(&tmp, &estr, &result);
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	printf("ret en gettoken es %d\n", result);
	return (result);
}
