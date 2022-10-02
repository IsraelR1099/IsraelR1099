/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:46:08 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/02 13:04:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	position;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1, 2))
			s1++;
	position = ft_strlen(s1);
	while (position && ft_strchr(set, s1[position], 2))
		position--;
	return (ft_substr(s1, 0, (position + 1)));
}
