/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/25 21:28:14 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

int	ft_in_find(char **pstr, char *estr)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp > estr)
	{
		if (*tmp == '"')
			return (1);
		tmp--;
	}
	return (0);
}

/*int	ft_true_quotes(char **equotes, char **estr)
{
	static unsigned char	in_quote = '"';

	while (*equotes < *estr && !ft_strchrflag("\t\r\n\v ", **equotes, in_quote))
	{
		if (**equotes == '"' && (**equotes != in_quote) && !in_quote)
		{
			in_quote = **equotes;
		}
		else if (**equotes == in_quote)
			in_quote = 0;
		*equotes++;
	}
	return (in_quote);
}
*/
int	ft_in_quotes(char **tmp, char **estr)
{
	char	*equotes;
	char	*aux;
	static unsigned char	in_quote = '"';

	equotes = *tmp;
//	ft_true_quotes(&equotes, estr);
	while (equotes < *estr && !ft_strchrflag("\t\r\n\v ", *equotes, in_quote))
	{
		if (*equotes == '"' && (*equotes != in_quote) && !in_quote)
		{
			in_quote = *equotes;
		}
		else if (*equotes == in_quote)
			in_quote = 0;
		equotes++;
	}
	equotes--;
	while (*equotes == '"')
		equotes--;
	aux = equotes;
	while (equotes > *tmp && ft_in_find(&aux, *tmp))
	{
		if (*equotes == '"')
			ft_swap(equotes + 1, equotes, 1);
		equotes--;
		if (equotes == *tmp && ft_in_find(&aux, *tmp))
		{
			equotes = aux;
			aux--;
		}
	}
	while (aux < *estr && !ft_strchr("\"", *aux) && ! ft_strchr("\t\r\n\v ", *aux))
		aux++;
	*tmp = aux;
	return (**tmp && ft_strchr("\"", **tmp));
}

int	ft_quotes(char **pstr, char **estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		count;

	tmp = *pstr;
	if (*tmp == 39)
		ft_quotes_simple(pstr, estr, ftoken, eftoken);
	else
	{
			count = 0;
		while (tmp < *estr && ft_strchr("\"", *tmp) && count++ >= 0)
			tmp++;
		if (ftoken)
			*ftoken = tmp;
		ft_in_quotes(&tmp, estr);
		if (eftoken)
			*eftoken = tmp;
		while (tmp < *estr && ft_strchr("\"", *tmp))// && count--)
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
	int		count;

	tmp = *pstr;
	count = 0;
	while (tmp < *estr && ft_strchr("\'", *tmp) && count++ >= 0)
		tmp++;
	if (ftoken)
		*ftoken = tmp;
	while (tmp < *estr && !ft_strchr("\'", *tmp))
		tmp++;
	if (eftoken)
		*eftoken = tmp;
	while (tmp < *estr && ft_strchr("\'", *tmp) && count--)
		tmp++;
	while (tmp < *estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*pstr = tmp;
	return (*tmp && ft_strchr("\'", *tmp));
}
