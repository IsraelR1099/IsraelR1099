/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/30 13:58:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_quotes(char *str, char *estr, char **pquotes, char **epquotes)
{
	char	*tmp;

	tmp = str;
	while (tmp < estr && *tmp != '"')
		tmp++;
	*pquotes = tmp;
	while (tmp < estr && *tmp != '"')
		tmp++;
	if (!tmp)
		ft_error("syntax error", 1);
	*epquotes = tmp;
	return (1);
}
