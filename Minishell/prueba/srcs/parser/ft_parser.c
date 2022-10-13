/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:19:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/13 17:41:58 by irifarac         ###   ########.fr       */
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
//	printf("cmd address parsecmd es %p\n", cmd);
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
	char	file[20];

//	printf("entro en parseredirs\n");
	while (ft_find(pstr, estr, "<>"))
	{
	//	printf("entro en while redirs\n");
		operator = gettoken(pstr, estr, 0, 0);
		if (gettoken(pstr, estr, &ftoken, &eftoken) != 'z')
			ft_error("syntax error near unexpected token 'newline'\n", 127);
		ft_memcpy(file, ftoken, eftoken - ftoken);
		file[eftoken - ftoken] = '\0';
//		printf("file es %s y ftoken %s\n", file, ftoken);
		if (operator == '<')
		{
			cmd = buildredir(cmd, ftoken, eftoken, O_RDONLY, 0);
		}
		else if (operator == '>')
		{
			if (access(file, F_OK) == 0)
				cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY | O_APPEND, 1);
			else
				cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY | O_CREAT |
				O_TRUNC, 1);
		}
		else if (operator == '+')
		{
			if (access(file, F_OK) == 0)
				cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY | O_CREAT | O_APPEND, 1);
			else
				cmd = buildredir(cmd, ftoken, eftoken, O_WRONLY | O_CREAT |
				O_APPEND, 1);
		}
		else if (operator ==  '-')
				cmd = buildredir(cmd, ftoken, eftoken, O_RDWR | O_CREAT |
				O_EXCL, 1);
	}
//	printf("salgo de parseredir\n");
	return (cmd);
}

struct cmd	*parseexec(char **pstr, char *estr)
{
	struct cmd		*ret;
	struct doexec	*cmd;
	int				token;
	char			*ftoken;
	char			*eftoken;

	//printf("entro en parseexec\n");
	ret = buildexec();
	ret = parseredirs(pstr, estr, ret);
	cmd = (struct doexec *)ret;
//	printf("ret address: %p\n", ret);
	while (!ft_find(pstr, estr, "|"))
	{
		//printf("entro en while parseexec\n");
		if ((token = gettoken(pstr, estr, &ftoken, &eftoken)) == 0)
			break ;
		if (token != 'z')
			ft_error("syntax", 1);
		if ((ft_setcmd(&cmd, ftoken, eftoken, 0) >= MAXARGS))
				break ;
//		printf("ftoken es %s y pstr es %s\n", ftoken, *pstr);
		//printf("while de parseexec antes\n");
		ret = parseredirs(pstr, estr, ret);
		//printf("while de parseexec despues\n");
	}
//	printf("salgo de exec\n");
	ft_setcmd(&cmd, ftoken, eftoken, 1);
//	printf("pstr es %s\n", *pstr);
	return (ret);
}
