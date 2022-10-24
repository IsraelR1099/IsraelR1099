/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/24 21:01:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static int	ft_in_find(char **pstr, char *estr)
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

static int	ft_in_quotes(char **tmp, char **estr)
{
	int		count;
	char	*equotes;
	char	*aux;

	count = 0;
	equotes = *tmp;
	printf("principio %p y equotes %p, %p\n", *tmp, equotes, equotes + 3);
	while (!ft_strchr("\t\r\n\v ", *equotes) && equotes < *estr)
	{
		equotes++;
		count++;
	}
	aux = equotes;
	equotes--;
	while (*equotes == '"')
		equotes--;
	printf("equotes %s, aux %s\n", equotes, aux);
	while (equotes > *tmp && ft_in_find(&aux, *tmp))
	{
		if (*equotes == '"')
		{
			printf("char quote %c, prev %c\n", *equotes, *(equotes + 1));
			ft_swap(equotes + 1, equotes, 1);
			printf("equotes dentro %s\n", equotes);
			aux--;
		}
		printf("equotes char %c\n", *equotes);
		equotes--;
		count--;
		if (equotes == *tmp && ft_in_find(&aux, *tmp))
			equotes = aux;
	}
	while (aux < *estr && !ft_strchr("\"", *aux))
		aux++;
	*tmp = aux;
	printf("count es %d y equotes %s, tmp %s\n", count, equotes, *tmp);
/*	while (*tmp < *estr && *tmp <= equotes)
	{
		printf("tmp dentro es %c\n", **tmp);
		*tmp = *tmp + 1;
	}*/
	return (**tmp && ft_strchr("\"", **tmp));
}

int	ft_quotes(char **pstr, char **estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		count;

	tmp = *pstr;
	printf("entro en quotes\n");
	if (*tmp == 39)
		ft_quotes_simple(pstr, estr, ftoken, eftoken);
	else
	{
			count = 0;
		while (tmp < *estr && ft_strchr("\"", *tmp) && count++ >= 0)
			tmp++;
		if (ftoken)
			*ftoken = tmp;
	//	while (tmp < estr && !ft_strchr("\"", *tmp))
	//		tmp++;
		ft_in_quotes(&tmp, estr);
		if (eftoken)
			*eftoken = tmp;
		while (tmp < *estr && ft_strchr("\"", *tmp) && count--)
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
