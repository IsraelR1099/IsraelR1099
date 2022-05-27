/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cases_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:25:14 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/25 22:25:18 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_general_solve(t_meta_data *meta)
{
	int	rst;

	rst = 0;
	rst += ft_presort_at_b(meta);
	rst += ft_spin_sort_at_a(meta);
	meta->moves = rst;
	return (rst);
}

int	ft_select_cases(t_meta_data *meta)
{
	if (meta->size <= 5)
		return (ft_small_cases(meta, 'a'));
	else
		return (ft_general_solve(meta));
	return (0);
}
