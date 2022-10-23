/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:40:40 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/20 18:03:24 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_find_elem_before(t_env *env, char *key)
{
	t_env	*aux;

	aux = env;
	while (aux != NULL)
	{
		if (ft_strcmp(aux->key, key) == 0)
			return (NULL);
		if (ft_strcmp(aux->next->key, key) == 0)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

t_env	*ft_find_elem(t_env *env, char *key)
{
	t_env	*aux;

	aux = env;
	while (aux != NULL)
	{
		if (ft_strcmp(aux->key, key) == 0)
		{
			return (aux);
		}
		aux = aux->next;
	}
	return (NULL);
}
