/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:34:06 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/21 21:48:52 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_find_marker(char *str)
{
	int	marker;

	marker = 0;
	while (str[marker] != 0)
	{
		if (str[marker] == 32 || str[marker] == 0)
			break ;
		marker++;
	}
	return (marker);
}

int	ft_is_builtin(char *buf)
{
	int			marker;
	int			i;
	char		*head;
	char		comparison_str[4096];
	static char	*built_ins[400] = {"echo", "export",
		"unset", "pwd", "cd", "exit", "env"};

	ft_bzero(comparison_str, 4096);
	i = -1;
	head = buf;
	while ((*buf))
	{
		if ((*buf) == '|' || (*buf) == '<' || (*buf) == '>')
			return (0);
		buf++;
	}
	buf = head;
	marker = ft_find_marker(buf);
	while (built_ins[++i])
	{
		if (!(ft_strcmp(ft_memcpy(comparison_str, buf, marker), built_ins[i])))
			return (1);
	}
	return (0);
}

t_cmd	*ft_builtparse(char *str)
{
	char		*estr;
	t_cmd		*cmd;

	estr = str + ft_strlen(str);
	cmd = ft_builtexec(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		printf("leftovers: %s\n", str);
		ft_error("syntax", 1);
	}
	ft_terminate(cmd);
	return (cmd);
}

t_cmd	*ft_builtexec(char **pstr, char *estr)
{
	char		*ftoken;
	char		*eftoken;
	int			token;
	t_cmd		*ret;
	t_doexec	*cmd;

	ret = ft_buildexec();
	cmd = (t_doexec *)ret;
	while (*pstr < estr)
	{
		token = ft_gettoken(pstr, estr, &ftoken, &eftoken);
		if (token != 'z')
			ft_error("syntax", 1);
		if ((ft_setcmd(&cmd, ftoken, eftoken, 0) >= MAXARGS))
			break ;
	}
	ft_setcmd(&cmd, ftoken, eftoken, 1);
	return (ret);
}
