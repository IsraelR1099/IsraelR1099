/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:59:20 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/31 13:19:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAXARGS 10
# define EXEC 1
# define PIPE 2
# define LIST 3

typedef struct s_cmd
{
	int type;
}	t_cmd;

typedef struct s_execcmd
{
	int	type;
	char *argv[MAXARGS];
	char *eargv[MAXARGS];
}	t_execcmd;

typedef struct s_pipecmd
{
	int	type;
	t_cmd	*left;
	t_cmd	*right;
}	t_pipecmd;

typedef struct s_listcmd
{
	int type;
	t_cmd	*left;
	t_cmd	*right;
}	t_listcmd;

void	*ft_memset(void *dst, int c, size_t n);
size_t	ft_strlen(const char *str);
void	ft_error(const char *str, char *ptr);
int		ft_fork1(void);
int		ft_find(char **ptr, char *estr, char *tokens);
int		ft_gettoken(char **pstr, char *estr, char **ftoken, char **eftoken);
#endif
