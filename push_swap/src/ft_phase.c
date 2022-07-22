/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:42:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/22 13:55:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_phase1(t_nbr **head, t_nbr **head_b, int counter)
{
//	t_nbr	*tmp = *head;
//	t_nbr	*tmp_b = *head_b;
	int		nbr;
//	int		i = 0;
	//printf("fase 1\n");
	while (ft_pcheck(head) != 2 )//&& i++ < 30)
	{
	//	nbr = ft_slst(head);
	//	if (nbr == 5)
	//		break ;
/*		tmp = *head;
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
		}*/
		if (ft_best_way(head, counter) == 2)
		{
			nbr = ft_groups(counter);
		//	printf("entro en best\n");
			while (nbr && ft_pcheck(head) != 2)
			{
				ft_rra(head);
				if (ft_condition_pb(head))
					ft_pb(head, head_b);
				nbr--;
			}
		}
		if (!ft_do_both(head, head_b, counter))
		{	
//		printf("hola en else\n");
			ft_do_stacka(head);
		}
		//printf("antes de condition\n");
		if (ft_condition_pb(head))
		{
			ft_pb(head, head_b);
		//	printf("despues de pb\n");
			if (!ft_do_both(head, head_b, counter))
				ft_do_stackb(head_b, head, counter);
//			printf("despues de stackb\n");
		}
//		printf("fuera de condition pb\n");
	}
	//printf("fuera de fase1\n");
	return (1);
}

int	ft_phase2(t_nbr **head, t_nbr **head_b, int counter)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	t_nbr	*last;
	int		i = 0;
	int		j;

	//printf("entro en phase2\n");
	while (!ft_check_sort(head, counter) && ft_slst(head) > 5) //&& i++ < 10)
	{
		//	printf("hola dentro\n");
		ft_inversions(head, head_b, counter);
	}
	ft_sort_5(head, head_b, counter);
/*	tmp = *head;
	//printf("despues de sort\n");
	while (tmp)
	{
		printf("data  es %d y priority %d index %d\n", tmp->data, tmp->priority, tmp->index);
		tmp = tmp->next;
	}
	tmp_b = *head_b;
	i = 0;
	while (tmp_b && i++ < 9)
	{
		printf("data b  es %d y priority %d index %d\n", tmp_b->data, tmp_b->priority, tmp_b->index);
		tmp_b = tmp_b->next;
	}*/
	last = ft_lastnode(*head);
	tmp_b = *head_b;
	while (ft_slst(head) != ft_groups(counter))
	{
		tmp = *head;
		i = ft_times(head, head_b);
		/*if (i == ft_slst(head))
		{
			ft_sb(head_b);
			i = ft_times(head, head_b);
		}*/
		j = i;
		while (i)
		{
			ft_ra(head);
			i--;
		}
		ft_pa(head, head_b);
		if ((*head)->priority < (*head)->next->priority)
			ft_sa(head);
		while (j)
		{
			ft_rra(head);
			j--;
		}
	}
/*	tmp = *head;
	while (tmp)
	{
		printf("data  es %d y priority %d index %d\n", tmp->data, tmp->priority, tmp->index);
		tmp = tmp->next;
	}
	tmp_b = *head_b;
	while (tmp_b)
	{
		printf("data b  es %d y priority %d index %d\n", tmp_b->data, tmp_b->priority, tmp_b->index);
		tmp_b = tmp_b->next;
	}
	printf("salgo de phase2\n");*/
	return (1);
}


