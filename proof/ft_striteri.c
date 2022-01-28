/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:51:41 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/21 16:22:03 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	marker;

	marker = 0;
	if (!s || !f)
		return ;
	while (s[marker] && s[marker] != '\0')
	{
		f(marker, &s[marker]);
		marker++;
	}
}
