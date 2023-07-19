/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:11:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/19 13:49:39 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static t_cmd	*ft_parseexec(char **str, char *estr)
{
	t_cmd		*ret;
	t_execcmd	*cmd;
	char		*ftoken;
	char		*eftoken;
	int			token;
	int			argc;

	ret = ft_buildexec();
	cmd = (t_execcmd *)ret;
	argc = 0;
	while (!ft_find(str, estr, "|"))
	{
		token = ft_gettoken(str, estr, &ftoken, &eftoken);
		if (token == 0)
			break ;
		if (token != 'z')
			ft_error("syntax", 1);
		cmd->argv[argc] = ftoken;
		cmd->eargv[argc] = eftoken;
		argc++;
		if (argc == MAXARGS)
			ft_error("too many arguments", 1);
	}
	cmd->argv[argc] = 0;
	cmd->eargv[argc] = 0;
	return (ret);
}

static t_cmd	*ft_parsepipe(char **str, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parseexec(str, estr);
	if (ft_find(str, estr, "|"))
	{
		ft_gettoken(str, estr, 0, 0);
		cmd = ft_buildpipe(cmd, ft_parsepipe(str, estr));
	}
	return (cmd);
}

static t_cmd	*ft_parseline(char **str, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parsepipe(str, estr);
	if (ft_find(str, estr, ";"))
	{
		ft_gettoken(str, estr, 0, 0);
		cmd = ft_buildback(cmd);
	}
	return (cmd);
}

t_cmd	*ft_parsecmd(char *str)
{
	char	*estr;
	t_cmd	*cmd;

	estr = ft_strlen(str) + str;
	cmd = ft_parseline(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		ft_error("syntax", 1);
	}
	return (cmd);
}
