/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:46:08 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/23 12:36:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	position;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
			s1++;
	position = ft_strlen(s1);
	while (position && ft_strchr(set, s1[position]))
		position--;
	return (ft_substr(s1, 0, (position + 1)));
}
