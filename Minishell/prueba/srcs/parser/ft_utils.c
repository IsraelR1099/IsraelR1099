/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/25 22:51:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static int	ft_list_redir(char **tmp, int *result)
{
	if (**tmp == 0)
		return (0);
	else if (**tmp == '<')
	{
		*tmp = *tmp + 1;
		if (**tmp == '<')
		{
			*result = '-';
			*tmp = *tmp + 1;
		}
	}
	else if (**tmp == '>')
	{
		*tmp = *tmp + 1;
		if (**tmp == '>')
		{
			*result = '+';
			*tmp = *tmp + 1;
		}
	}
	return (1);
}

static int	ft_case(char **tmp, char **estr, int *result)
{
//	static unsigned char	in_quote = 1;
	char	*end;
	char	*beginning;

	if (**tmp == 0)
		return (0);
	else if (**tmp == '|')
		*tmp = *tmp + 1;
	else if (**tmp == '<' || **tmp == '>')
		ft_list_redir(tmp, result);
	else
	{
		*result = 'z';
		end = *tmp;
		beginning = *tmp;
		ft_end(&end, estr);
		printf("end es %c anterios %c\n", *end, *(end - 1));
		while (*tmp < *estr && !ft_strchr("\t\r\n\v ", **tmp)
			&& !ft_strchr("<|>", **tmp))
		{
			if (**tmp == '"' && ft_in_find(&end, beginning))
			{
				ft_in_quotes(&beginning, estr);
			}
			*tmp = *tmp + 1;
		}
	}
	printf("leftover %s\n", *tmp);
	return (1);
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
	printf("gett tmp |%s|\n", tmp);
	if (*tmp == 34 || *tmp == 39)
	{
		printf("entro en quotes\n");
		ft_quotes(pstr, &estr, ftoken, eftoken);
		result = 'z';
		return (result);
	}
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	result = *tmp;
	if (ft_case(&tmp, &estr, &result) == 0)
		return (0);
	if (eftoken)
		*eftoken = tmp;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (result);
}
