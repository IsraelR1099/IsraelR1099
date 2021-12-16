/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:13 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/14 15:18:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	*str;	
	int	nbr;

	str = "hooolsdaso";
	nbr = ft_strlen(str);
	printf("%d\n", nbr);
	return (0);
}
