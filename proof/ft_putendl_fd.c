/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:43:42 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/22 12:20:22 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}
