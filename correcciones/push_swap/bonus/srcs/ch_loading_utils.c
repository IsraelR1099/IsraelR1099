/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_loading_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:26:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:12:21 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static int	ft_check_input(t_meta_data *meta, int num)
{
	t_stacks	*node;

	if (meta->first_a == NULL)
		return (1);
	else
	{
		node = meta->first_a;
		while (node)
		{
			if (num == node->value)
				return (0);
			node = node->next;
		}
		return (1);
	}
}

static t_stacks	*ft_create_elem(t_meta_data *meta, int value)
{
	t_stacks	*node;

	if (ft_check_input(meta, value) == 0)
		return (NULL);
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	meta->size++;
	return (node);
}

int	ft_check_input_limits(char **input, t_meta_data *meta)
{
	int	i;

	if (ft_strncmp(input[meta->init], "--count", 7) == 0)
	{
		meta->count = 1;
		meta->init++;
	}
	i = meta->init;
	while (input[i])
	{
		if (ft_send_to_atoi(input[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

t_meta_data	*ft_meta_data_init(void)
{
	t_meta_data	*rst;

	rst = (t_meta_data *)malloc(sizeof(t_meta_data));
	if (rst == NULL)
		return (NULL);
	rst->size = 0;
	rst->moves = 0;
	rst->error = 0;
	rst->count = 0;
	rst->init = 0;
	rst->first_a = NULL;
	rst->first_b = NULL;
	return (rst);
}

int	ft_load_stack(char **input, t_meta_data *meta)
{
	int			i;
	t_stacks	*stack;
	t_stacks	*new;

	i = meta->init;
	while (input[i])
	{
		if (ft_send_to_atoi(input[i]) != 1)
			return (0);
		new = ft_create_elem(meta, ft_atoi(input[i]));
		if (new == NULL)
			return (0);
		if (meta->first_a == NULL)
		{
			stack = new;
			meta->first_a = new;
		}
		else
		{
			stack->next = new;
			stack = stack->next;
		}
		i++;
	}
	return (1);
}
