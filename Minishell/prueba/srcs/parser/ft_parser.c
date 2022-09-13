/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:19:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/13 12:40:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

struct cmd	*parsecmd(char *str)
{
	char		*estr;
	struct cmd	*cmd;
//	struct doexec	*execmd;

	estr = str + ft_strlen(str);
//	printf("entro en parsecmd\n");
	cmd = parseline(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		printf("leftovers: %s\n", str);
		ft_error("syntax");
	}
	terminate(cmd);
//	execmd = (struct doexec *)cmd;
//	printf("ecm type %s\n", execmd->names[0]);
//	printf("ecm type %s\n", execmd->names[1]);
	return (cmd);
}

struct cmd	*parseline(char **pstr, char *estr)
{
	struct cmd	*cmd;

//	printf("entro en parseline\n");
	cmd = parsepipe(pstr, estr);
	return (cmd);
}

struct cmd	*parsepipe(char **pstr, char *estr)
{
	struct cmd	*cmd;

//	printf("entro en parsepipe\n");
	cmd = parseexec(pstr, estr);
	if (ft_find(pstr, estr, "|"))
	{
	//	printf("entro en pipe\n");
		gettoken(pstr, estr, 0, 0);
		cmd = buildpipe(cmd, parsepipe(pstr, estr));
	//	printf("cmd left %d\n", cmd->type);
	}
	return (cmd);
}

struct cmd	*parseredirs(char **pstr, char *estr, struct cmd *cmd)
{
	char	*ftoken;
	char	*eftoken;
	int		operator;

//	printf("entro en parseredirs\n");
	while (ft_find(pstr, estr, "<>"))
	{
//		printf("entro en redirs\n");
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
	struct cmd		*ret;
	struct doexec	*cmd;
	int				token;
	int				i;
	char			*ftoken;
	char			*eftoken;

//	printf("entro en parseexec\n");
	ret = buildexec();
	ret = parseredirs(pstr, estr, ret);
	cmd = (struct doexec *)ret;
	i = 0;
	while (!ft_find(pstr, estr, "|") && i < 10)
	{
		if ((token = gettoken(pstr, estr, &ftoken, &eftoken)) == 0)
			break ;
		if (token != 'z')
			ft_error("syntax");
		cmd->names[i] = ftoken;
		cmd->end_names[i] = eftoken;
		i++;
		ret = parseredirs(pstr, estr, ret);
	}
	cmd->names[i] = 0;
	cmd->end_names[i] = 0;
//	printf("salgo de exec\n");
	return (ret);
}
