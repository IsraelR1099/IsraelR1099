/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:43:42 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/22 12:04:37 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	marker;

	marker = 0;
	if (!s || !fd)
		return ;
	while (s[marker] != '\0')
	{
		ft_putchar_fd(s[marker], fd);
		marker++;
	}
}
