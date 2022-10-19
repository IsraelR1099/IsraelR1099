/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:19:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/19 12:16:08 by irifarac         ###   ########.fr       */
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
		ft_error("syntax", 1);
	}
	terminate(cmd);
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
	char	file[20];

	while (ft_find(pstr, estr, "<>"))
	{
		operator = gettoken(pstr, estr, 0, 0);
/*		if (gettoken(pstr, estr, &ftoken, &eftoken) != 'z')
			ft_error("syntax error near unexpected token 'newline'\n", 127);
		ft_memcpy(file, ftoken, eftoken - ftoken);
		file[eftoken - ftoken] = '\0';
		if (operator == '<')
			cmd = buildredir(cmd, ftoken, eftoken, O_RDONLY, 0);
		else if (operator == '>')
		{
			if (access(file, F_OK) == 0)
				cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY | O_APPEND, 1);
			else
				cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY | O_CREAT
						| O_TRUNC, 1);
		}
		else if (operator == '+')
		{
			if (access(file, F_OK) == 0)
				cmd = buildredir(cmd, ftoken, eftoken, WCA, 1);
			else
				cmd = buildredir(cmd, ftoken, eftoken, WCA, 1);
		}
		else if (operator == '-')
				cmd = buildredir(cmd, ftoken, eftoken, RDCE, 1);*/
		if (gettoken(pstr, estr, &ftoken, &eftoken) != 'z')
			ft_error("syntax error near unexpected token 'newline'\n", 127);
		ft_memcpy(file, ftoken, eftoken - ftoken);
		file[eftoken - ftoken] = '\0';
		printf("ftoken |%s|, eftoken |%s| y operator %d y file %s\n", ftoken, eftoken, operator, file);
	//	cmd = buildredir(cmd, ftoken, eftoken, O_RDONLY, 0);
		if (operator == '<' || operator == '>')
		{
			printf("entro en operator\n");
			ft_simple_redir(cmd, &ftoken, &eftoken, operator);
		}
	/*	else if (operator == '>')
		{
			if (access(file, F_OK) == 0)
			cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY |
			O_APPEND, 1);
			else
				cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY | O_CREAT
				| O_TRUNC, 1);
		}*/
		else if (operator == '+')
		{
			if (access(file, F_OK) == 0)
				cmd = buildredir(cmd, ftoken, eftoken, WCA, 1);
			else
				cmd = buildredir(cmd, ftoken, eftoken, WCA, 1);
		}
		else if (operator == '-')
			cmd = buildredir(cmd, ftoken, eftoken, RDCE, 1);
	}
	return (cmd);
}

struct cmd	*parseexec(char **pstr, char *estr)
{
	struct cmd		*ret;
	struct doexec	*cmd;
	int				token;
	char			*ftoken;
	char			*eftoken;

	ret = buildexec();
	ret = parseredirs(pstr, estr, ret);
	cmd = (struct doexec *)ret;
	while (!ft_find(pstr, estr, "|"))
	{
		token = gettoken(pstr, estr, &ftoken, &eftoken);
		if (token == 0)
			break ;
		if (token != 'z')
			ft_error("syntax", 1);
		if ((ft_setcmd(&cmd, ftoken, eftoken, 0) >= MAXARGS))
			break ;
		ret = parseredirs(pstr, estr, ret);
	}
	ft_setcmd(&cmd, ftoken, eftoken, 1);
	return (ret);
}
