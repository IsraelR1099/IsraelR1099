/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/26 22:38:25 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static int	ft_in_find(char **pstr, char *estr)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp >= estr)
	{
		if (*tmp == '"')
			return (1);
		tmp--;
	}
	return (0);
}

static void	ft_find_end(char **equotes, char **estr, char token)
{
	static unsigned char	in_quote;

	in_quote = token;
	while (*equotes < *estr && !ft_strchrflag("\t\r\n\v ", **equotes, in_quote))
	{
		if (**equotes == token && (**equotes != in_quote) && !in_quote)
			in_quote = **equotes;
		else if (**equotes == in_quote)
			in_quote = 0;
		*equotes = *equotes + 1;
		if (*equotes == *estr || **equotes == ' ')
		{
			*equotes = *equotes - 1;
			break ;
		}
	}
}

int	ft_in_quotes(char **tmp, char **estr, char token)
{
	char	*equotes;
	char	*aux;

	equotes = *tmp;
	ft_find_end(&equotes, estr, token);
	while (*equotes == token)
		equotes--;
	aux = equotes;
	while (equotes > *tmp && ft_in_find(&aux, *tmp))
	{
		if (*equotes == token)
			ft_swap(equotes + 1, equotes, 1);
		equotes--;
		if (equotes == *tmp && ft_in_find(&aux, *tmp))
		{
			equotes = aux;
			if (*(aux - 1) == token)
				aux--;
			if (*aux == token)
				aux--;
		}
	}
	while (aux < *estr && !ft_strchr("\"\'", *aux) && !ft_strchr("\t\r\n\v ", *aux))
		aux++;
	*tmp = aux;
	return (**tmp && ft_strchr("\"", **tmp));
}

int	ft_quotes(char **pstr, char **estr, char **ftoken, char **eftoken)
{
	char	*tmp;

	tmp = *pstr;
	if (*tmp == 39)
		ft_quotes_simple(pstr, estr, ftoken, eftoken);
	else
	{
		while (tmp < *estr && ft_strchr("\"", *tmp))
			tmp++;
		if (ftoken)
			*ftoken = tmp;
		ft_in_quotes(&tmp, estr, '"');
		if (eftoken)
			*eftoken = tmp;
		while (tmp < *estr && ft_strchr("\"", *tmp))
			tmp++;
		while (tmp < *estr && ft_strchr("\t\r\n\v ", *tmp))
			tmp++;
		*pstr = tmp;
	}
	return (*tmp && ft_strchr("\"", *tmp));
}

int	ft_quotes_simple(char **pstr, char **estr, char **ftoken, char **eftoken)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < *estr && ft_strchr("\'", *tmp))
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	//while (tmp < *estr && !ft_strchr("\'", *tmp))
	//	tmp++;
	ft_in_quotes(&tmp, estr, '\'');
	if (eftoken)
		*eftoken = tmp;
	while (tmp < *estr && ft_strchr("\'", *tmp))
		tmp++;
	while (tmp < *estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (*tmp && ft_strchr("\'", *tmp));
}

int	ft_true_quotes(char **pstr, char *estr)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < estr && !ft_strchr("\t\r\n\v ", *tmp))
	{
		if (*tmp == '"' || *tmp == '\'')
			return (1);
		tmp++;
	}
	return (0);
}

//void	ft_change_token(char **pstr, char *estr, char **ftoken, char **eftoken)
void	ft_change_token(char **pstr, char *estr)
{
	char			*tmp;
	int				counter;
	int				len;
	unsigned char	in_quote;
	char			copy[256];
	int				i;

	tmp = *pstr;
	counter = 0;
	len = 0;
	i = 0;
	ft_memset(copy, 0, sizeof(copy));
	while (tmp < estr && !ft_strchrflag("\t\r\n\v ", *tmp, in_quote)
		&& !ft_strchrflag("<|>", *tmp, in_quote))
	{
		if (ft_strchr("\"\'", *tmp) && (*tmp != in_quote) && !in_quote)
		{
			in_quote = *tmp;
			counter++;
		}
		else if (*tmp == in_quote)
		{
			in_quote = 0;
			counter++;
		}
		else if (*tmp != in_quote)
		{
			copy[i] = *tmp;
			i++;
		}
		tmp++;
		len++;
	}
	printf("counter es %d, len %d\n", counter, len);
	printf("copy es %s\n", copy);
	if (counter == 2)
		return ;
	tmp = *pstr;
	while (tmp < estr && !ft_strchr("\t\r\n\v ", *tmp)
		&& !ft_strchrflag("<|>", *tmp, in_quote))
	{
	//	if (*tmp == '"' || *tmp == '\'')
	//		printf("hola\n");
		tmp++;
	}
}
