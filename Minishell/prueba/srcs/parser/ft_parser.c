/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:19:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/07 13:14:40 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

struct cmd	*parsecmd(char *str)
{
	char		*estr;
	struct cmd	*cmd;

	estr = str + ft_strlen(str);
	cmd = parseline(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		printf("leftovers: %s\n", str);
		ft_error("syntax");
	}
	//nulterminate(cmd);
	return (cmd);
}

struct cmd	*parseline(char **pstr, char *estr)
{
	struct cmd	*cmd;

	cmd = parsepipe(pstr, estr);
	return (cmd);
}

struct cmd	*parsepipe(char **pstr, char *estr)
{
	struct cmd	*cmd;

	cmd = parseexec(pstr, estr);
	if (ft_find(pstr, estr, "|"))
	{
		gettoken(pstr, estr, 0, 0);
		cmd = buildpipe(cmd, parsepipe(pstr, estr));
	}
	return (cmd);
}

struct cmd	*parseredirs(char **pstr, char *estr, struct cmd *cmd)
{
	char	*ftoken;
	char	*eftoken;
	int		operator;

	while (ft_find(pstr, estr, "<>"))
	{
		operator = gettoken(pstr, estr, 0, 0);
		if (gettoken(pstr, estr, &ftoken, &eftoken) != 'z')
			ft_error("syntax error near unexpected token 'newline'\n");
		if (operator == '<')
			cmd = buildredir(cmd, ftoken, eftoken, O_RDONLY, 0);
		else if (operator == '>')
			cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY|O_CREAT, 1);
		else if (operator == '+')
			cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY|O_CREAT, 1);
	}
	return (cmd);
}

struct cmd	*parseexec(char **pstr, char *estr)
{
	struct cmd	*ret;

	ret = parseredirs(pstr, estr, ret);
/*	while (ft_find(pstr, estr, "|") <= 0)
	{
	}*/
	return (ret);
}
