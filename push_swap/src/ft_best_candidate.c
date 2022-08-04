/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_candidate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:40:56 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/04 15:40:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int    ft_move_b(t_nbr **head, t_nbr **head_b)
{
    t_nbr   *tmp_b;
    int     nbr;
    int     down;
    int     up;
  //  int     result;

    tmp_b = *head_b;
    (void)head;
    up = 0;
    nbr = ft_max_value(head_b);
   // printf("nbr es %d\n", nbr);
//    result = 0;
    while (tmp_b )//&& result++ < 20)
    {
        if (tmp_b->data == nbr)
            break ;
        tmp_b = tmp_b->next;
        up++;
    }
    down = ft_slst(head_b) - up;
    tmp_b = *head_b;
    //printf("down es %d y up %d\n", down, up);
    if (up < down)
    {
        while (tmp_b->data != nbr)
        {
            tmp_b = *head_b;
           // printf("data es %d\n", tmp_b->data);
            if (tmp_b->data == nbr)
                break ;
            ft_rb(head_b);
        }
    }
    else
    {
        while (tmp_b->data != nbr)
        {
            tmp_b = *head_b;
            //printf("data es %d\n", tmp_b->data);
            if (tmp_b->data == nbr)
                break ;
            ft_rrb(head_b);
        }
     }
    return (nbr);
}
