/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:45:13 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/31 13:47:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	ft_runcmd(t_cmd *cmd, char **env)
{
	t_execcmd	*exec;
	t_pipecmd	*pipe;
	t_listcmd	*list;

	if (cmd == 0)
		return ;
	if (cmd->type == EXEC)
	{
		if(exec->argv[0] = 0)
			exit (1);

