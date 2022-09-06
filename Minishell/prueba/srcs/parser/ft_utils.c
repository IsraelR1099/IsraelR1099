/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:00 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/06 20:30:49 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str) + 1);
	exit (1);
}

int	fork1(void)
{
	int	pid;

	printf("entro en fork1\n");
	pid = fork();
	if (pid == -1)
		ft_error("fork");
	return (pid);
}
