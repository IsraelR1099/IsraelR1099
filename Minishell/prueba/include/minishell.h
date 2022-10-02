/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/02 20:57:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include <sys/ioctl.h>

# define EXEC 1
# define REDIR 2
# define PIPE 3
# define MAXARGS 10
//# define O_RONLY	0x000
//# define O_WRONLY	0x001
//# define O_RDWR		0x002
//# define O_CREAT	0x200

typedef struct cmd
{
	int	type;
}	cmd;

typedef struct doexec
{
	int		type;
	char	*names[10];
	char	*end_names[10];
}	doexec;

typedef struct doredir
{
	int			type;
	struct cmd	*cmd;
	char		*file;
	char		*efile;
	int			right;
	int			fd;
}	doredir;

typedef struct dopipe
{
	int			type;
	struct cmd	*left;
	struct cmd	*right;
}	dopipe;

//Parsing
struct cmd	*parsecmd(char *str);
struct cmd	*parseline(char **pstr, char *estr);
struct cmd	*parsepipe(char **pstr, char *estr);
struct cmd	*parseredirs(char **pstr, char *estr, struct cmd *cmd);
struct cmd	*parseexec(char **pstr, char *estr);
void		ft_runcmd(struct cmd *cmd);
//Building tree structs
struct cmd	*buildexec(void);
struct cmd	*buildredir(struct cmd *scmd, char *file, char *efile, int right, int fd);
struct cmd	*buildpipe(struct cmd *left, struct cmd *right);
// Null terminate strings
struct cmd	*terminate(struct cmd *cmd);
//Signals
void		ft_handler(int signo);
void		ft_info_handler(int signo, siginfo_t *info, void *context);
//Utils
void		ft_error(char *str, int exit_code);
int			fork1(void);
int			ft_find(char **pstr, char *estr, char *tokens);
int			gettoken(char **pstr, char *estr, char **ftoken, char **eftoken);
int			ft_execvp(char *file, char *argv[], char *envp[]);
int			ft_setcmd(struct doexec **cmd, char *ftoken, char *eftoken, int sign);
int			ft_quotes(char *str, char *estr, char **pquotes, char **epquotes);

#endif
