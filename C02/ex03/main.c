/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:05:56 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/16 15:37:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main()
{
	char	str[] = "2";
	int	x;

	x = ft_str_is_numeric(str);
	printf("%d\n", x);
	return (0);

}
