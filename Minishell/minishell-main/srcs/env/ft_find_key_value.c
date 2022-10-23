/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:39:10 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/18 22:48:31 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_find_key(char *pattern)
{
	int		i;

	i = 0;
	if (!pattern)
		return (0);
	while (pattern[i] != 0 && pattern[i] != '=')
		i++;
	return (i);
}

int	ft_find_value(char *pattern)
{
	int		i;

	i = 0;
	if (!pattern)
		return (0);
	while (pattern[i] != '=' && pattern[i] != 0)
		i++;
	if (pattern[i] == 0)
		return (i + 1);
	else if (pattern[i] == '=' && pattern[i + 1] == 0)
		return (i + 1);
	i++;
	return (i);
}	
