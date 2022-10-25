/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:27:29 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/25 20:41:39 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

int	ft_end(char **str, char **estr)
{
	char	*tmp;
	char	*beginning;

	tmp = *str;
	beginning = tmp;
	while (tmp < *estr && !ft_strchr("\t\r\n\v ", *tmp))
	{
		tmp++;
	}
	while (tmp > beginning && *tmp == '"')
		tmp--;
	*str = tmp;
	return (0);
}
