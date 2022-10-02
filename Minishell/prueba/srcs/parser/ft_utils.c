/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/02 20:58:22 by irifarac         ###   ########.fr       */
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
//	printf("--entro en ft_find tmp %s\n", tmp);
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp, 2))
		tmp++;
	*pstr = tmp;
	printf("retorno %d y token es %s\n", (*tmp && ft_strchr(tokens, *tmp, 2)), tokens);
	return (*tmp && ft_strchr(tokens, *tmp, 2));
}

int	gettoken(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char		*tmp;
	int			result;
	static int	flag_quote;

	tmp = *pstr;
	printf("flag_quote es %d y tmp %s\n", flag_quote, tmp);
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp, flag_quote))
	{
	/*	if (*tmp == 34)
		{
			//printf("entro en while\n");
			flag_quote = 1;
		}*/
		tmp++;
	}
	if (*tmp == 34)
	{
		flag_quote = 1;
		tmp++;
	}
	if (ftoken)
		*ftoken = tmp;
	printf("flag_quote despues es %d\n", flag_quote);
	if (flag_quote == 1 && (*tmp == '|'
		|| *tmp == '<' || *tmp == '>'))
	{
	//	printf("entro en if\n");
		result = 'z';
	}
	else
		result = *tmp;
	//printf("result es %d\n", result);
	if (*tmp == 0)
		return (0);
	else if (*tmp == '|')
		tmp = tmp + 1;
	else if (*tmp == '<')
		tmp = tmp + 1;
	//else if (*tmp == '$')
	//	ft_expand(ftoken);
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
		printf("tmp antes antes es #%s# y flag es %d\n", tmp, flag_quote);
		while (tmp < estr && !ft_strchr("\t\r\n\v ", *tmp, 2)
			&& !ft_strchr("<|>", *tmp, flag_quote))
		{
			printf("tmp es %c\n", *tmp);
			if (*tmp == 34)
				flag_quote = 0;
			tmp = tmp + 1;
		}
	}
//	ft_case(&tmp, &estr, &result);
	if (eftoken)
		*eftoken = tmp;
	printf("tmp al final antes es #%s# y flag_quote %d\n", tmp, flag_quote);
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp, 2))
	{
		tmp++;
	//	if (*tmp == 34)
	//		flag_quote = 0;
	}
	printf("tmp al final es #%s# y flag_quote %d\n", tmp, flag_quote);
	*pstr = tmp;
	return (result);
}
