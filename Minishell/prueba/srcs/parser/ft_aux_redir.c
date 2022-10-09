/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:39:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/08 21:09:57 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	p_struct(struct cmd *cmd, struct cmd *srcmd[])
{
	struct cmd		*tmp;
	struct doredir	*tmpredir;
//	struct cmd		*pcmd[_POSIX_OPEN_MAX];
	int				i;

	printf("entro en pstruct\n");
	i = 0;
	tmp = cmd;
	while (tmp->type == 2 || tmp->type == 1)
	{
		printf("entro en bucle pstruct tmp: %p\n", tmp);
		tmpredir = (struct doredir *)tmp;
		srcmd[i] = tmp;
		tmp = tmpredir->cmd;
		i++;
	}
}