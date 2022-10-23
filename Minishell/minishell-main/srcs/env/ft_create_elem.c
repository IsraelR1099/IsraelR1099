/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:15:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/21 16:14:40 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_create_elem(t_env *new, char *key_value, int value_start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	new = (t_env *) ft_calloc(1, sizeof(t_env));
	new->key = (char *) ft_calloc(value_start, 1);
	new->value = (char *) ft_calloc((
				ft_strlen(key_value) - value_start) + 1, 1);
	if (!new || !new->key || !new->value)
		return (NULL);
	while (++i < value_start)
		new->key[i - 1] = key_value[i - 1];
	i = 0;
	while (*(key_value + value_start + i) != 0)
		new->value[++j - 1] = key_value[value_start + (++i - 1)];
	new->value[j] = 0;
	if (key_value[value_start - 1] == 0)
	{
		free(new->value);
		new->value = NULL;
	}
	new->next = NULL;
	return (new);
}
