/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:42:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/04 20:56:30 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_phase1(t_nbr **head, t_nbr **head_b, int counter)
{
	int		nbr;

	while (ft_pcheck(head) != 2 )
	{
		if (ft_best_way(head, counter) == 2)
		{
			nbr = ft_groups(counter);
			while (nbr && ft_pcheck(head) != 2)
			{
				ft_rra(head);
				if (ft_condition_pb(head))
					ft_pb(head, head_b);
				nbr--;
			}
		}
		if (!ft_do_both(head, head_b, counter))
			ft_do_stacka(head);
		if (ft_condition_pb(head))
		{
			ft_pb(head, head_b);
			if (!ft_do_both(head, head_b, counter))
				ft_do_stackb(head_b, head, counter);
		}
	}
	return (1);
}

int	ft_phase2(t_nbr **head, t_nbr **head_b, int counter)
{
	int		i;
	int		j;

	while (!ft_check_sort(head, counter) && ft_slst(head) > 5)
		ft_inversions(head, head_b, counter);
	ft_sort_5(head, head_b, counter);
	while (ft_slst(head) != ft_groups(counter))
	{
		i = ft_times(head, head_b);
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
	return (1);
}

/*int	ft_phase3(t_nbr **head, t_nbr **head_b, int counter)
{
//	t_nbr	*tmp;
//	t_nbr	*tmp_b;
//    t_nbr   *last;
    //int     group;
	//int     up;
	//int     down;
    //int     i;
   // int     j;
//    int     count = 0;

//	tmp = *head;
//	tmp_b = *head_b;
	while (!ft_check_sort(head, counter) && *head_b && ft_slst(head) <
    (counter - 1))
 //   && count++ < 50)
	{
        tmp = *head;
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
        ft_move_b(head, head_b);
        i = ft_times_noprio(head, head_b);
        j = i;
		up = ft_best_up(head_b, counter);
		down = ft_best_down(head_b, counter);
        if (up == down || ft_groups(counter) >= ft_slst(head_b))
            down = MIN_INT;
        //printf("times es %d y up %d down %d\n", i, up, down);
		if (up > down)
		{
            while (i)
            {
                ft_ra(head);
                i--;
            }
            ft_pa(head, head_b);
	    	if ((*head)->data > (*head)->next->data)
	    		ft_sa(head);
	    	while (j)
	    	{
	    		ft_rra(head);
                last = ft_lastnode(*head);
                if (*head_b && (*head_b)->data < (*head)->data &&
                    (*head_b)->data > last->data)
                    ft_pa(head, head_b);
	    		j--;
	    	}
        }
        else
        {
            group = ft_groups(counter);
            while (group)
            {
                ft_rrb(head_b);
                if ((*head_b)->next->data > (*head_b)->data)
                    ft_sb(head_b);
                group--;
            }
        }
        ft_pa(head, head_b);
   }
	tmp = *head;
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
    return (1);
}*/

int	ft_phase3(t_nbr **head, t_nbr **head_b, int counter)
{
    t_nbr   *last;
    t_nbr   *tmpa;
    t_nbr   *tmp_b;
    int     count = 0;
    int     times;


    while (ft_slst(head) < (counter - 1) && *head_b && count++ < 20)
    {
        tmpa = *head;
        tmp_b = *head_b;
        while (tmpa)
        {
            printf("data es %d\n", tmpa->data);
            tmpa = tmpa->next;
        }
        int i = 0;
        while (tmp_b && i++ < 10)
        {
            printf("data b es %d\n", tmp_b->data);
            tmp_b = tmp_b->next;
        }
        last = ft_lastnode(*head);
        if ((*head_b)->data < (*head)->data)
        {
            ft_pa(head, head_b);
        }
        else
        {
            if ((*head_b)->data < (*head)->next->data
                && (*head_b)->data > (*head)->data)
            {
                ft_ra(head);
                ft_pa(head, head_b);
                last = ft_lastnode(*head);
                printf("last es %d\n", last->data);
                if (last->data > (*head_b)->data)
                    ft_rra(head);
            }
            else
            {
               times = ft_times_noprio(head, head_b);
               while (times)
               {
                    ft_ra(head);
                    times--;
               }
            }
        }
    }
    return (1);
}
