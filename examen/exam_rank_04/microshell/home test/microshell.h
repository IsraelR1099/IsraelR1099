/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:43:29 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/25 18:07:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

# define MAXARGS 10
# define EXEC 1
# define PIPE 2
# define BACK 3

typedef struct s_cmd
{
	int	type;
}	t_cmd;

typedef struct s_exec
{
	int		type;
	char	*argv[MAXARGS];
	char	*eargv[MAXARGS];
}	t_execcmd;

typedef struct s_pipe
{
	int		type;
	t_cmd	*left;
	t_cmd	*right;
}	t_pipecmd;

typedef struct s_back
{
	int		type;
	t_cmd	*cmd;
}	t_backcmd;

void	ft_error(const char *str, size_t value);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *dest, int ch, size_t count);
int		ft_fork1(void);
int		ft_find(char **pstr, char *estr, char *tokens);
t_cmd	*ft_parsecmd(char *str);
int		ft_gettoken(char **pstr, char *estr, char **ftoken, char **eftoken);
t_cmd	*ft_buildexec(void);
t_cmd	*ft_buildpipe(t_cmd *left, t_cmd *right);
t_cmd	*ft_buildback(t_cmd *subcmd);
void	ft_runcmd(t_cmd *cmd, char **envp);

#endif
