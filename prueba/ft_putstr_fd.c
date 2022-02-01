/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:35:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/01 20:52:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	/*int	position;
	int	len;

	len = ft_strlen(s);
	position = 0;
	while (s[position] != '\0')
	{
		write(fd, &s[position], len);
		position++;
	}*/
	write(fd, &s, 1);
}
