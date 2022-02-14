/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:08:43 by cteixido          #+#    #+#             */
/*   Updated: 2022/01/31 11:34:48 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (i < len && start < ft_strlen(s))
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
