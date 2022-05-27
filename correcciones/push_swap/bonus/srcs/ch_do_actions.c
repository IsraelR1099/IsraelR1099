/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_do_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:30 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 22:48:37 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_do_push(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_push_action(meta, 'b');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_push_action(meta, 'a');
		return (1);
	}
	return (0);
}

int	ft_do_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_rotate_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_rotate_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_rotate_action(meta, 'a');
		ft_rotate_action(meta, 'b');
		return (1);
	}
	return (0);
}

int	ft_do_reverse_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_reverse_rotate_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_reverse_rotate_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_reverse_rotate_action(meta, 'a');
		ft_reverse_rotate_action(meta, 'b');
		return (1);
	}
	return (0);
}

int	ft_do_swap(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_swap_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_swap_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_swap_action(meta, 'a');
		ft_swap_action(meta, 'b');
		return (1);
	}
	return (0);
}

int	ft_get_command(t_meta_data *meta, char *line)
{
	if (ft_strlen(line) > 3)
		return (ft_do_reverse_rotate(meta, (char)(ft_strncmp(line, "rr", 3))));
	else
	{
		if (line[0] == 'p')
			return (ft_do_push(meta, (char)(ft_strncmp(line, "p", 2))));
		if (line[0] == 's')
			return (ft_do_swap(meta, (char)(ft_strncmp(line, "s", 2))));
		if (line[0] == 'r')
			return (ft_do_rotate(meta, (char)(ft_strncmp(line, "r", 2))));
	}
	return (0);
}
