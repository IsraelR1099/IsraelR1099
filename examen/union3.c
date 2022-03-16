/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:14:09 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/16 21:30:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define CHARS 256

size_t	ft_strlen(char const *str)
{
	size_t	position;

	position = 0;
	while (*(str + position))
		position++;
	return (position);
}

char	*remove_dup(char *str)
{
	bool	bin_hash[CHARS] = {0};
	int	position;
	int	position2;
	int	temp;

	position = 0;
	position2 = 0;
	while (*(str + position))
	{
		temp = *(str + position);
		if (bin_hash[temp] == 0)
		{
			bin_hash[temp] = 1;
			*(str + position2) = *(str + position);
			position2++;
		}
		position++;
	}
	*(str + position2) = '\0';
	return (str);
}

int	main(int counter, char **str)
{
	char	*ptr;
//	char	*ptr2;
//	char	*ptr3;
//	char	temp[CHARS];
//	int	position;
//	int	position2;

	if (counter == 3)
	{
//		position = 0;
//		position2 = 0;
		ptr = remove_dup(str[1]);
//		ptr2 = remove_dup(str[2]);
		write(1, ptr, ft_strlen(ptr));
/*		printf("hola\n");
//		write(1, ptr2, ft_strlen(ptr2));
//		printf("\n");
		while (*(ptr + position))
		{
			*(temp + position) = *(ptr + position);
			position++;
		}
		while (*(ptr2 + position2))
			*(temp + position++) = *(ptr2 + position2++);
		*(temp + position) = '\0';
		ptr3 = remove_dup(temp);
		write(1, ptr3, ft_strlen(ptr3));*/
	}
	write(1, "\n", 1);
	return (0);
}
