/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:19:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/21 21:48:35 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

t_cmd	*ft_parsecmd(char *str)
{
	char		*estr;
	t_cmd		*cmd;

	estr = str + ft_strlen(str);
	cmd = ft_parseline(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		printf("leftovers: %s\n", str);
		ft_error("syntax", 1);
	}
	ft_terminate(cmd);
	return (cmd);
}

t_cmd	*ft_parseline(char **pstr, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parsepipe(pstr, estr);
	return (cmd);
}

t_cmd	*ft_parsepipe(char **pstr, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parseexec(pstr, estr);
	if (ft_find(pstr, estr, "|"))
	{
		ft_gettoken(pstr, estr, 0, 0);
		cmd = ft_buildpipe(cmd, ft_parsepipe(pstr, estr));
	}
	return (cmd);
}

t_cmd	*ft_parseredirs(char **pstr, char *estr, t_cmd *cmd)
{
	char	*ftoken;
	char	*eftoken;
	int		operator;

	while (ft_find(pstr, estr, "<>"))
	{
		operator = ft_gettoken(pstr, estr, 0, 0);
		if (ft_gettoken(pstr, estr, &ftoken, &eftoken) != 'z')
			ft_error("syntax error near unexpected token 'newline'\n", 127);
		if (operator == '<' || operator == '>')
			cmd = ft_simple_redir(cmd, &ftoken, &eftoken, operator);
		else if (operator == '+' || operator == '-')
			cmd = ft_double_redir(cmd, &ftoken, &eftoken, operator);
	}
	return (cmd);
}

t_cmd	*ft_parseexec(char **pstr, char *estr)
{
	t_cmd		*ret;
	t_doexec	*cmd;
	int			token;
	char		*ftoken;
	char		*eftoken;

	ret = ft_buildexec();
	ret = ft_parseredirs(pstr, estr, ret);
	cmd = (t_doexec *)ret;
	while (!ft_find(pstr, estr, "|"))
	{
		token = ft_gettoken(pstr, estr, &ftoken, &eftoken);
		if (token == 0)
			break ;
		if (token != 'z')
			ft_error("syntax", 1);
		if ((ft_setcmd(&cmd, ftoken, eftoken, 0) >= MAXARGS))
			break ;
		ret = ft_parseredirs(pstr, estr, ret);
	}
	ft_setcmd(&cmd, ftoken, eftoken, 1);
	return (ret);
}
