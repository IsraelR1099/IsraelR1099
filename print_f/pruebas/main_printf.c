/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/01 13:51:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	result;
	int	ejemplo;

	ejemplo = 2;
	result = printf("123%i456%d\n", ejemplo, ejemplo);
	printf("result es %d\n", result);
	return (0);
}
