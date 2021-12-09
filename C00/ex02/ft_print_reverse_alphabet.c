/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:32:55 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/08 12:53:02 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_reverse_alphabet(void)
{
	char	i;
	char	a;

	i = 'z';
	a = ' ';
	while (i >= 'a')
	{
		write(1, &i, 1);
		write(1, &a, 1);
	i--;
	}
	write(1, "\n", 1);
}	
