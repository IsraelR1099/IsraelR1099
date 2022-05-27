/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clear_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:04:27 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 11:04:29 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_delete_node(t_stacks *node)
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
		free (meta);
}

int	ft_clear_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		i++;
		while (i-- > 0)
			free (split[i]);
		i++;
		free (split);
	}
	return (0);
}

int	ft_clear_all(t_meta_data *meta)
{
	if (meta)
	{
		ft_clear_nodes(meta->first_a);
		ft_clear_nodes(meta->first_b);
		ft_clear_nodes(meta->pivot);
		ft_clear_stack(meta);
	}
	return (0);
}
