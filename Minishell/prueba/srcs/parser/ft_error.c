/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:16:04 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/30 18:24:51 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

void	ft_error(char *str, int exit_code)
{
	write(2, str, ft_strlen(str) + 1);
	exit((unsigned char)exit_code);
}
