/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:47:34 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/08 13:52:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_numbers(void)
{
	char	number;
	char	space;

	number = '0';
	space = ' ';
	while (number <= '9')
	{
		write(1, &number, 1);
		write(1, &space, 1);
		number++;
	}
	write(1, "\n", 1);
}
