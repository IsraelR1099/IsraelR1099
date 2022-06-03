/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:26:30 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/03 13:31:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"
#include "../Libft/libft.h"

int	ft_checker(char **str, int counter)
{
	int	position;
	int	index;

	position = 0;
	index = 1;
	while (*(*(str + index) + position))
	{
		if (!(ft_not_nbr(*(*(str + index) + position)))
			|| ft_dup(str, counter))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		position++;
		if (!(*(*(str + index) + position)))
		{
			index++;
			position = 0;
			if (index == counter)
				break ;
		}
	}
	return (1);
}

int	ft_not_nbr(char c)
{
	if (c == '-')
		return (1);
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	ft_dup(char **str, int counter)
{
	int	index;
	int	*nbrs;

	index = 1;
	nbrs = (int *)malloc(sizeof(int) * (counter - 1));
	if (!(nbrs))
		return (0);
	while (*(str + index) && !(index == counter))
	{
		nbrs[index - 1] = ft_atoi(&*(*(str + index) + 0));
		if (nbrs[index - 1] < MIN_INT || nbrs[index - 1] > MAX_INT)
		{
			free(nbrs);
			return (1);
		}
		index++;
	}
	if (ft_intdup(nbrs, counter))
	{
		free(nbrs);
		return (1);
	}
	free(nbrs);
	return (0);
}

int	ft_intdup(int *nbrs, int counter)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = counter - 1;
	while (i < (count - 1))
	{
		j = i + 1;
		while (j < count)
		{
			if (nbrs[i] == nbrs[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
