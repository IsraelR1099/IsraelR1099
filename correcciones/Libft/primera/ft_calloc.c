/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:29:37 by cteixido          #+#    #+#             */
/*   Updated: 2022/01/20 17:54:34 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	all_size;
	void	*dst;

	all_size = count * size;
	dst = malloc(all_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, all_size);
	return (dst);
}
