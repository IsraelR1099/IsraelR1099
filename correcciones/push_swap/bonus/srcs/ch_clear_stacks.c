/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_clear_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:04:27 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:06:48 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static void	ft_delete_node(t_stacks *node)
{
	if (node)
	{
		node->next = NULL;
		free (node);
	}
}

static void	ft_clear_nodes(t_stacks *node)
{
	t_stacks	*tmp;

	while (node)
	{
		tmp = node->next;
		ft_delete_node(node);
		node = tmp;
	}
}

static void	ft_clear_stack(t_meta_data *meta)
{
	if (meta)
	{
		meta->first_a = NULL;
		meta->first_b = NULL;
		free (meta);
	}
}

int	ft_clear_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (split[0])
	{
		while (i-- > 0)
			free (split[i]);
		i++;
	}
	free (split);
	return (0);
}

int	ft_clear_all(t_meta_data *meta)
{
	if (meta)
	{
		ft_clear_nodes(meta->first_a);
		ft_clear_nodes(meta->first_b);
		ft_clear_stack(meta);
	}
	return (0);
}
