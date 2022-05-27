/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:29:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:28:39 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_check_solve(t_meta_data *meta)
{
	int			i;
	int			prev;
	t_stacks	*stack;

	i = 0;
	if (meta->first_b != NULL)
		return (0);
	stack = meta->first_a;
	prev = stack->value;
	while (stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}

int	ft_list_size(t_stacks *first_node)
{
	t_stacks	*node;
	int			i;

	node = first_node;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	ft_check_error_solve(void)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (1);
	return (0);
}

void	ft_print_results(int msg, t_meta_data *meta)
{
	if (msg == 0)
		ft_putendl_fd("KO", STDOUT_FILENO);
	if (msg == 1)
	{
		if (meta->count == 1)
		{
			ft_putstr_fd("size: ", STDOUT_FILENO);
			ft_putnbr_fd(meta->size, STDOUT_FILENO);
			ft_putstr_fd(" | ", STDOUT_FILENO);
			ft_putnbr_fd(meta->moves, STDOUT_FILENO);
			ft_putstr_fd(" moves ", STDOUT_FILENO);
		}
		ft_putendl_fd("OK", STDOUT_FILENO);
	}
	if (msg == 2)
		ft_putendl_fd("Error", STDERR_FILENO);
}
