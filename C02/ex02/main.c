/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:06:55 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/16 15:01:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main()
{
	int	x;
	char	str[] = "hola?aa";

	x = ft_str_is_alpha(str);
	printf("%d\n", x);
	return (0);
}
