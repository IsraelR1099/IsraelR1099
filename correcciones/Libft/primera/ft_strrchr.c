/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:50:22 by cteixido          #+#    #+#             */
/*   Updated: 2022/01/19 12:21:45 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			ss = (char *)(s + i);
		i++;
	}
	if (s[i] == (const char)c)
		ss = (char *)(s + i);
	return (ss);
}
