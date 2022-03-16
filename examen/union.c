/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:11:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/16 20:49:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
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

char	*remove_duplicates(char *str)
{
	bool	bin_hash[CHARS] = {0};
	int	ip_ind;
	int	res_ind;
	int	temp;

	ip_ind = 0;
	res_ind = 0;
	while (*(str + ip_ind))
	{
		temp = *(str + ip_ind);
		if (bin_hash[temp] == 0)
		{
			bin_hash[temp] = 1;
			*(str + res_ind) = *(str + ip_ind);
			res_ind++;
		}
		ip_ind++;
	}
	*(str + res_ind) = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	char	*ptr2;
	char	*ptr3;
	char	temp[256];
	int	position;
	int	position2;
	char	*ptr4;

	if (argc == 3)
	{
		ptr2 = remove_duplicates(argv[1]);
		ptr3 = remove_duplicates(argv[2]);
		position = 0;
		while (*(ptr2 + position))
		{
			*(temp + position) = *(ptr2 + position);
			position++;
		}
		while (*(ptr3 + position2))
			*(temp + position++) = *(ptr3 + position2++);
		*(temp + position) = '\0';
		ptr4 = remove_duplicates(temp);
		write(1, ptr4, ft_strlen(ptr4));
	}
	write(1, "\n", 1);
	return (0);
}
