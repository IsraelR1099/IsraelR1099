/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:25:23 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/12 10:26:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*ptr1;

	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	ptr1 = malloc ((lens1 + lens2 + 1) * 1);
	if (ptr1 == NULL)
		return (0);
	if (ptr1)
	{
		ft_memcpy(ptr1, s1, lens1);
		ft_memcpy(ptr1 + lens1, s2, lens2 + 1);
	}
	ptr1[lens1 + lens2] = '\0';
	return (ptr1);
}
