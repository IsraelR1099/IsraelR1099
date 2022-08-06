/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:14:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/06 13:54:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void    ft_pass_positive(t_nbr **head, int counter)
{
    t_nbr   *tmp;
    t_nbr   *tmp_op;
    int     nbr;
    int     minus;
    int     result;

    tmp = *head;
    minus = 1;
    result = MIN_INT;
    ft_set_pos(head);
    while (tmp)
    {
        tmp_op = *head;
        nbr = MAX_INT;
        while (tmp_op)
        {
            if (nbr > tmp_op->data)
            {
                if (result < tmp_op->data)
                {
                    nbr = tmp_op->data;
                    tmp_op->positive = counter - minus;
                }
            }
            tmp_op = tmp_op->next;
        }
        result = nbr;
        minus++;
        tmp = tmp->next;
    }
}

void    ft_set_pos(t_nbr **head)
{
    t_nbr   *tmp;

    tmp = *head;
    while (tmp)
    {
        tmp->positive = 0;
        tmp = tmp->next;
    }
}

int ft_check_pos(t_nbr **head, int counter, int group)
{
    t_nbr   *tmp;
    int     condition;

    tmp = *head;
    condition = counter - 1 - group;
    while (tmp)
    {
        if (tmp->positive >= condition)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
