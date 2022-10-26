/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/26 21:01:36 by irifarac         ###   ########.fr       */
/*   Updated: 2022/10/25 21:28:28 by irifarac         ###   ########.fr       */
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
#include <limits.h>

# define EXEC 1
# define REDIR 2
# define PIPE 3
# define MAXARGS 10
# define RWRR (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# define WCA O_WRONLY | O_CREAT | O_APPEND
# define RDCE O_RDWR | O_CREAT | O_EXCL

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
struct cmd	*builtparse(char *str);
struct cmd	*builtexec(char **pstr, char *estr);
void		ft_runcmd(struct cmd *cmd);
void		ft_heredoc(struct cmd *cmd);
//Building tree structs
struct cmd	*buildexec(void);
//struct cmd	*buildredir(struct cmd *scmd, char *file, char *efile, int right, int fd);
struct cmd	*buildredir(struct cmd *scmd, char *file, char *efile,
int pointers[2]);
struct cmd	*buildpipe(struct cmd *left, struct cmd *right);
// Null terminate strings
struct cmd	*terminate(struct cmd *cmd);
//Signals
//void		ft_handler(int signo);
void		ft_info_handler(int signo, siginfo_t *info, void *context);
void		ft_handler(int signo, siginfo_t *info, void *context);
//Quotes
int			ft_quotes(char **pstr, char **estr, char **ftoken, char **eftoken);
int			ft_quotes_simple(char **pstr, char **estr, char **ftoken, char **eftoken);
int			ft_in_quotes(char **tmp, char **estr, char token);
int			ft_true_quotes(char **equotes, char *estr);
//void		ft_change_token(char **pstr, char *estr, char **ftoken, char
//**eftoken);
void		ft_change_token(char **pstr, char *estr);
int			ft_end(char **str, char **estr);
//Utils
void		ft_error(char *str, int exit_code);
void		*ft_swap(void *dest, void *src, size_t count);
int			fork1(void);
int			ft_find(char **pstr, char *estr, char *tokens);
int			gettoken(char **pstr, char *estr, char **ftoken, char **eftoken);
int			ft_execvp(char *file, char *argv[], char *envp[]);
int			ft_setcmd(struct doexec **cmd, char *ftoken, char *eftoken, int sign);
void		p_struct(struct cmd *cmd, struct cmd *srcmd[]);
void		ft_redir_exec(struct cmd *cmd);
struct cmd	*ft_simple_redir(struct cmd *cmd, char **ftoken, char **eftoken, int operator);
struct cmd	*ft_double_redir(struct cmd *cmd, char **ftoken, char **eftoken, int operator);

#endif
