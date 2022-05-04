/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:45:23 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/04 14:06:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int counter, char **str)
{
	char	*ptr;

	ptr = str[2];
	printf("%s\n", ptr);
	ptr = str[4];
	printf("%s, %d\n", ptr, counter);
	return (0);
}
