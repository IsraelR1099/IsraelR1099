/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:50:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/27 20:05:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

int	ft_in_quotes(char *tmp, unsigned char *in_quote, int *counter)
{
	if (ft_strchr("\"\'", *tmp) && (*tmp != *in_quote)
		&& !*in_quote)
	{
		*in_quote = *tmp;
		*counter = *counter + 1;
		return (1);
	}
	else if (*tmp == *in_quote)
	{
		*in_quote = 0;
		*counter = *counter + 1;
		return (1);
	}
	return (0);
}
