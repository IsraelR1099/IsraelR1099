/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:55:49 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/08 13:36:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"
#include "../Libft/libft.h"

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit (1);
}

int ft_no_valid(char **str, int counter)
{
    int position;
    int index;

    position = 0;
    index = 1;
    if (!*(*(str + index) + position))
        ft_error();
    while (*(*(str + index) + position))
    {
        position++;
        if (!*(*(str + index) + position))
        {
            if (!ft_atoi(*(str + index)) &&
                    *(*(str + index)) != '0')
                ft_error();
            index++;
            position = 0;
            if (index == counter)
                break ;
            if (!*(*(str + index) + position))
                ft_error();
        }
    }
    return (1);
}
