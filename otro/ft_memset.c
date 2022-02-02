/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:34:04 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/21 13:38:34 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;
	size_t			i;

	ptr = s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = a;
		i++;
	}
	return (s);
}
