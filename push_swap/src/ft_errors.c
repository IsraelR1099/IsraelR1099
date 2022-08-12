/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:26:30 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/12 14:10:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"
#include "../Libft/libft.h"

static int	ft_not_nbr(char c)
{
	if (c == '-')
		return (1);
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

static int	ft_intdup(long *nbrs, int counter)
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

static int	ft_dup(char **str, int counter)
{
	int		index;
	long	*nbrs;

	index = 1;
	nbrs = (long *)malloc(sizeof(long) * (counter - 1));
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

int	ft_checker(char **str, int counter)
{
	int	position;
	int	index;

	position = 0;
	index = 1;
	ft_no_valid(str, counter);
	while (*(*(str + index) + position))
	{
		if (!(ft_not_nbr(*(*(str + index) + position)))
			|| ft_dup(str, counter))
		{
			write(2, "Error\n", 6);
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

int	ft_check_sort(t_nbr **head, int counter)
{
	t_nbr	*tmp;
	int		nbr;
	int		len;
	int		lenhead;

	tmp = *head;
	nbr = MIN_INT;
	len = 0;
	lenhead = ft_slst(head);
	while (tmp)
	{
		if (tmp->data > nbr)
		{
			nbr = tmp->data;
			len++;
		}
		tmp = tmp->next;
	}
	if (len == (counter - 1))
		return (1);
	else if (len == (lenhead))
		return (1);
	return (0);
}
