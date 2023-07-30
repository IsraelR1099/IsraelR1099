/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecmd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:39:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/30 20:46:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

t_cmd	*ft_parseline(char **pstr, char *estr)
{
	t_cmd *cmd;

	cmd = ft_parsepipe(pstr, estr);
	if (ft_find(pstr, estr, ";"))
	{
		ft_gettoken(pstr, estr, 0, 0);
		cmd = ft_buildback(cmd);
	}
	return (cmd);
}

t_cmd	*ft_parsecmd(char *str)
{
	char	*estr;

	estr = str + ft_strlen(str);
	cmd = ft_parseline(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
		ft_error("syntax error near unexpected token `;'", 128);
	ft_nullterminate(cmd);
	return (cmd);
}
