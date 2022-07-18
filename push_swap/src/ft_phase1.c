/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:42:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/18 14:10:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_phase1(t_nbr **head, t_nbr **head_b, int counter)
{
	t_nbr	*tmp = *head;
	t_nbr	*tmp_b = *head_b;
	int		nbr;
	int		i = 0;
	//printf("fase 1\n");
	nbr = ft_groups(counter);
	while (ft_pcheck(head) != 2 && i++ < 30)
	{
		if (ft_best_way(head, counter) == 2)
		{
			printf("entro en best\n");
			while (nbr)
			{
				ft_rra(head);
				nbr--;
			}
		}
		if (!ft_do_both(head, head_b, counter))
		{	
			printf("hola en else\n");
			ft_do_stacka(head);
		}
		printf("antes de condition\n");
		if (ft_condition_pb(head))
		{
			ft_pb(head, head_b);
			printf("despues de pb\n");
			if (!ft_do_both(head, head_b, counter))
				ft_do_stackb(head_b, head, counter);
			printf("despues de stackb\n");
		}
		printf("fuera de condition pb\n");
		
		tmp = *head;
		while (tmp)
		{
			printf("data  es %d y priority %d index %d\n", tmp->data, tmp->priority, tmp->index);
			tmp = tmp->next;
		}
		tmp_b = *head_b;
		while (tmp_b)
		{
			printf("data b es %d index b %d\n", tmp_b->data, tmp_b->index);
			tmp_b = tmp_b->next;
		}
	}
	printf("fuera de fase1\n");
	return (1);
}

int	ft_phase2(t_nbr **head, t_nbr **head_b, int counter)
{
	while (!ft_check_sort(head, counter))
	{
		if (!ft_do_both(head, head_b, counter))
		{	
			//printf("hola en else\n");
			ft_do_stacka(head);
		}
	}
	return (1);
}


