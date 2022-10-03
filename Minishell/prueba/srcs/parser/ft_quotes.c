/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/03 12:12:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

int	ft_quotes(char **pstr, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;

	tmp = *pstr;
//	printf("entro en quotes tmp #%s#\n", tmp);
	tmp++;
	if (ftoken)
		*ftoken = tmp;
	while (tmp < estr && !ft_strchr("\"", *tmp))
	{
//		printf("entro en while tmp es %c\n", *tmp);
		tmp++;
	}
	if (eftoken)
		*eftoken = tmp;
	if (*tmp == 34)
		tmp++;
	else
		ft_error("syntax error quoting", 1);
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
	{
//		printf("entro en while espacio\n");
		tmp++;
	}
	*pstr = tmp;
//	printf("tmp al final de quotes es #%s#\n", tmp);
	return (*tmp && ft_strchr("\"", *tmp));
}
