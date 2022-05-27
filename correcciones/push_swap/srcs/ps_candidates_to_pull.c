/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_candidates_to_pull.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:41:52 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/07 23:41:56 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_fix_distance_candidate(t_meta_data *meta, int i)
{
	int	size;

	size = ft_list_size(meta->first_b);
	if (size == 0)
		return (1);
	if (i > size / 2)
		return ((size - i + 1) * -1);
	else
		return (--i);
}

static int	ft_best_candidate(t_meta_data *meta)
{
	t_stacks	*candidate;
	int			best;
	int			i;
	int			to_beat;
	int			place_a;

	candidate = meta->first_b;
	best = meta->first_b->value;
	i = 1;
	to_beat = ft_find_place(meta, meta->first_b->value);
	while (candidate)
	{
		place_a = ft_find_place(meta, candidate->value);
		if (ft_absolute(place_a)
			+ ft_absolute(ft_fix_distance_candidate(meta, i))
			< ft_absolute(to_beat))
		{
			best = candidate->value;
			to_beat = ft_absolute(place_a)
				+ ft_absolute(ft_fix_distance_candidate(meta, i));
		}
		candidate = candidate->next;
		i++;
	}
	return (best);
}

int	ft_prepare_spin(t_meta_data *meta)
{
	int	spin_best;
	int	index;

	spin_best = ft_best_candidate(meta);
	if (spin_best == meta->first_b->value)
		return (0);
	index = ft_fix_distance_candidate(meta,
			ft_get_index_from_value(meta, 'b', spin_best));
	if (index < 0)
	{
		index = index * -1;
		return (ft_do_while(meta, index, 'b', &ft_do_reverse_rotate));
	}
	else
		return (ft_do_while(meta, index, 'b', &ft_do_rotate));
}
