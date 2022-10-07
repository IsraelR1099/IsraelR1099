/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:34:06 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/07 12:35:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

struct cmd	*builtparse(char *str)
{
	char		*estr;
	struct cmd	*cmd;

	estr = str + ft_strlen(str);
	cmd = builtexec(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		printf("leftovers: %s\n", str);
		ft_error("syntax", 1);
	}
	terminate(cmd);
	return (cmd);
}

struct cmd	*builtexec(char **pstr, char *estr)
{
	char			*ftoken;
	char			*eftoken;
	int				token;
	struct cmd		*ret;
	struct doexec	*cmd;

	ret = buildexec();
	cmd = (struct doexec *)ret;
	while ((token = gettoken(pstr, estr, &ftoken, &eftoken)) != 0)
	{
		if (token != 'z')
			ft_error("syntax", 1);
		if ((ft_setcmd(&cmd, ftoken, eftoken, 0) >= MAXARGS))
			break ;
	}
	ft_setcmd(&cmd, ftoken, eftoken, 1);
	return (ret);
}
