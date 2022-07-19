/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:07:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/18 17:30:00 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_sort_3(t_nbr **head, int counter)
{
	int	max;
	int	min;

	max = ft_max_nbr(*head);
	min = ft_min_nbr(*head);
	if (ft_check_sort(head, counter))
		return ;
	if (max == 1 && min == 2)
		ft_rra(head);
	else if (max == 1 && min == 0)
	{
		ft_rra(head);
		ft_sa(head);
	}
	else if (min == 1 && max == 2)
		ft_sa(head);
	else if (max == 0 && min == 2)
	{
		ft_sa(head);
		ft_rra(head);
	}
	else if (max == 0 && min == 1)
		ft_ra(head);
}

void	ft_sort_4(t_nbr **head, t_nbr **head_b, int counter)
{
	int	min;
	int	max;

	min = ft_min_nbr(*head);
	max = ft_max_nbr(*head);
	if (ft_check_sort(head, counter))
		return ;
	if (min == 0)
	{
		ft_pb(head, head_b);
		ft_sort_3(head, counter);
		ft_pa(head, head_b);
	}
	else if (max == 0)
		ft_utilsort_max4(head, head_b, counter);
	else if (min == 1 || max == 1)
	{
		ft_sa(head);
		ft_sort_4(head, head_b, counter);
	}
	else if (min == 3 || max == 3)
	{
		ft_rra(head);
		ft_sort_4(head, head_b, counter);
	}
}

void	ft_sort_5(t_nbr **head, t_nbr **head_b, int counter)
{
	int	min;
	int	max;

	min = ft_min_nbr(*head);
	max = ft_max_nbr(*head);
	if (ft_check_sort(head, counter))
		return ;
	if (min == 0)
		ft_utilsort_min5(head, head_b, counter);
	else if (max == 0)
		ft_utilsort_max5(head, head_b, counter);
	else if (min == 1 || max == 1)
	{
		ft_sa(head);
		ft_sort_5(head, head_b, counter);
	}
	else if (min == 4 || max == 4)
		ft_utilsort_m4(head, head_b, counter);
	else if (min == 3 || max == 3)
	{
		ft_rra(head);
		ft_sort_5(head, head_b, counter);
	}
}

void	ft_algorithm(t_nbr **head, t_nbr **head_b, int counter)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	int		i;
	int		size;

	tmp = *head;
	tmp_b = *head_b;
	ft_priority(head, counter);
	i = 0;
//(void)i;
	(void)tmp;
	(void)tmp_b;
	while (!ft_is_sort(head, counter) && i++ < 55 /* && ft_slst(head) < (counter - 1)*/)
	{
		//printf("hola arriba\n");
		size = ft_slst(head_b);
		if (ft_pcheck(head) && ft_check_sort(head, counter))
		{	
			//printf("hola\n");
			while (!ft_is_sort(head, counter) && size >= 1) //&& i++ < 50)
			{
				if (ft_condition_pa(head, head_b))
					ft_pa(head, head_b);
			//	printf("hola despues de if \n");
				if (!ft_do_both(head, head_b, counter))
				{
					size = ft_slst(head_b);
				tmp_b = *head_b;
				while (tmp_b)
				{
				//	printf("data b es %d\n", tmp_b->data);
					tmp_b = tmp_b->next;
				}
					ft_do_stackb(head_b, head, counter);
					//printf("hola fuera\n");
				}
			}
			//printf("salimos\n");
			continue ;
		}
		ft_phase1(head, head_b, counter);
		exit (1);
	//	printf("cambio de fase\n");
		ft_phase2(head, head_b, counter);
	/*	else
		{
//			printf("hola en else fuera\n");
			if (!ft_do_both(head, head_b, counter))
			{	
				printf("hola en else\n");
				ft_do_stacka(head);
			}
		}
//		printf("antes de condition\n");
		if (ft_condition_pb(head))
		{
			ft_pb(head, head_b);
//			printf("despues de pb\n");
			if (!ft_do_both(head, head_b, counter))
				ft_do_stackb(head_b, head, counter);
//			printf("despues de stackb\n");
		}
//		printf("fuera de condition pb\n");*/
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
		//exit (1);
	//printf("%d\n", i);
	}
/*	tmp = *head;
	while (tmp)
	{
		printf("data es %d e index %d y priority es %d\n", tmp->data, tmp->index, tmp->priority);
		tmp = tmp->next;
	}
	while (*head_b)
	{
		printf("data b es %d y priority es %d\n", (*head_b)->data, (*head_b)->priority);
		*head_b = (*head_b)->next;
	}*/
}


