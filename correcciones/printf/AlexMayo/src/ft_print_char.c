/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:53:41 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/24 11:59:27 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char(char c)
{
	return (write (1, &c, 1));
}

int	ft_print_perc(void)
{
	return (write(1, "%", 1));
}
