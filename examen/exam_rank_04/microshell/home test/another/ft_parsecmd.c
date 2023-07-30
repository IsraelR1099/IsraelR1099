/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:25:17 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/26 18:03:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static t_cmd	*ft_parseexec(char **str, char *estr)
{
	t_cmd	*cmd;
	t_exec	*ret;
	char	*ftoken;
	char	*eftoken;
	int		argc;
	int		token;

static t_cmd	*ft_parsepipe(char **str, char *estr)
{
	t_cmd *cmd;

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
	if (ft_find(str, estr ";"))
	{
		ft_gettoken(str, estr, 0, 0);
		cmd = ft_buildbakc(cmd);
	}
	return (cmd);
}

t_cmd	*ft_parsecmd(char *str)
{
	t_cmd	*cmd;
	char	*estr;

	estr = str + ft_strlen(str);
	cmd = ft_parseline(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		ft_error("syntax error near unexpected token", 1);
		return (NULL);
	}
	return (cmd);
	ft_nullterminate(cmd);
}
