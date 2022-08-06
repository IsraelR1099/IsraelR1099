/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:42:33 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/06 13:00:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void    ft_aux(t_nbr **head, t_nbr **head_b)
{
    t_nbr   *tmp;
    t_nbr   *tmp_b;

    tmp = *head;
    tmp_b = *head_b;
    while (tmp)
    {
        printf("data es %d, priority %d, positive %d y index %d\n", tmp->data, tmp->priority, tmp->positive, tmp->index);
        tmp = tmp->next;
    }
    while (tmp_b)
    {
        printf("data b es %d, priority %d y positive %d\n", tmp_b->data, tmp_b->priority, tmp_b->positive);
        tmp_b = tmp_b->next;
    }
}
