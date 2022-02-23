/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:06:29 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/02 13:40:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	number = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = n * -1;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((char)(number % 10) + 48, fd);
}
