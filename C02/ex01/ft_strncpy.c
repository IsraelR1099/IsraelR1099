/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:39:01 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/16 13:32:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	nbr;
	
	nbr = 0;
	while(nbr < n  && src[nbr] != '\0')
	{
		dest[nbr] = src[nbr];
		nbr++;
	}
	while (nbr < n)
	{
		dest[nbr] = '\0';
		nbr++;
	}
	return (dest);
}
