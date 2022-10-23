/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:31:46 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 13:02:52 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define EXEC 1
# define REDIR 2
# define PIPE 3
# define MAXARGS 250
# define RWRR (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# define WCA O_WRONLY | O_CREAT | O_APPEND
# define RDCE O_RDWR | O_CREAT | O_EXCL
# define BUFFER_SIZE 4096

extern int	g_exit;

typedef struct s_env
{
	char			*key;
	char			*value;
	char			**envp;
	int				lst_len;
	struct s_env	*next;
}		t_env;

typedef struct s_cmd
{
	int	type;
}	t_cmd;

typedef struct s_doexec
{
	int		type;
	char	*names[MAXARGS];
	char	*end_names[MAXARGS];
}	t_doexec;

typedef struct s_doredir
{
	int		type;
	t_cmd	*cmd;
	char	*file;
	char	*efile;
	int		right;
	int		fd;
}	t_doredir;

typedef struct s_dopipe
{
	int			type;
	t_cmd		*left;
	t_cmd		*right;
}		t_dopipe;

//Parsing
t_cmd	*ft_parsecmd(char *str);
t_cmd	*ft_parseline(char **pstr, char *estr);
t_cmd	*ft_parsepipe(char **pstr, char *estr);
t_cmd	*ft_parseredirs(char **pstr, char *estr, t_cmd *cmd);
t_cmd	*ft_parseexec(char **pstr, char *estr);
t_cmd	*ft_terminate(t_cmd *cmd);
t_cmd	*ft_builtexec(char **pstr, char *estr);
t_cmd	*ft_builtparse(char *str);
void	ft_heredoc(t_cmd *cmd, t_env *env);
int		ft_quotes_simple(char **pstr,
			char *estr, char **ftoken, char **eftoken);
void	ft_runcmd(t_cmd *cmd, t_env *env);
int		ft_prompt_parser(char **buf, t_env *env);
int		ft_setcmd(t_doexec **cmd,
			char *ftoken, char *eftoken, int sign);
int		ft_quotes(char **pstr, char *estr, char **ftoken, char **eftoken);
int		ft_is_builtin(char *buf);
void	ft_redir_exec(t_cmd *cmd);
t_cmd	*ft_simple_redir(t_cmd *cmd,
			char **ftoken, char **eftoken, int operator);
t_cmd	*ft_double_redir(t_cmd *cmd,
			char **ftoken, char **eftoken, int operator);
void	ft_p_struct(t_cmd *cmd, t_cmd *srcmd[]);
void	ft_prompt_expander(char **buf, t_env *env);
void	ft_error(char *str, int exit_code);

//Building tree structs
t_cmd	*ft_buildexec(void);
t_cmd	*ft_buildredir(t_cmd *scmd,
			char *file, char *efile, int pointers[2]);
t_cmd	*ft_buildpipe(t_cmd *left, t_cmd *right);
//Utils
void	ft_error(char *str, int exit_code);
int		ft_fork1(void);
int		ft_find(char **pstr, char *estr, char *tokens);
int		ft_gettoken(char **pstr, char *estr, char **ftoken, char **eftoken);
void	ft_heredoc(t_cmd *cmd, t_env *env);

//Env
t_env	*ft_init_env(char **main_env);
t_env	*ft_create_elem(t_env *new, char *key_value, int value_start);
int		ft_envsize(t_env *env);
char	**ft_create_envp(t_env *env);
//t_env   *ft_create_elem(t_env *new, char *env_variable);
t_env	*ft_find_elem(t_env *env, char *key);
t_env	*ft_find_elem_before(t_env *env, char *key);
int		ft_find_key(char *pattern);
int		ft_find_value(char *pattern);
char	*ft_expand(t_env *env, char *key);
void	ft_free_env(t_env *env, int err);
void	ft_free_envp(char **envp);
//void    ft_update_var(char *key, char *value, t_env *list);
void	ft_alphabetic_env(t_env *env);
int		ft_var_name_check(char *str, int len);
int		ft_var_name_stop(char *str);
int		ft_update_var(char *key_value, int value_start, t_env *env);

// exec
int		ft_run_builtin(t_env **env, char **buf);
int		ft_execve(t_env *env, char **names);
int		ft_find_command(t_doexec *cmd, t_env **env);
// void	ft_word_to_lower(char *command);
int		ft_is_file_or_dir(char *str);
int		ft_is_file(const char *path);

// signals
void	ft_info_handler(int signo, siginfo_t *info, void *context);
void	ft_handler(int signo);
void	ft_signals(void);
void	ft_termios(void);

//Built-ins
int		ft_env(t_env *env, char **names);
int		ft_export(char **names, t_env *env);
int		ft_pwd(t_env *env);
int		ft_echo(char **names);
int		ft_unset(char **names, t_env **env);
int		ft_cd(t_env *env, char **names);
void	ft_exit(char **names);

#endif
