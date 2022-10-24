/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:04:25 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/24 20:20:30 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_swap(void *dest, void *src, size_t count)
{
	char	tmp;
	char	*ptr;
	char	*ptr_src;

	ptr = (char *)dest;
	ptr_src = (char *)src;
	tmp = *ptr;
	printf("dest %c y src %c\n", *ptr, *ptr_src);
	while (count--)
	{
		*ptr = *ptr_src;
		*ptr_src = tmp;
	}
	return (dest);
}

