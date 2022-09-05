/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:40:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/05 13:55:51 by irifarac         ###   ########.fr       */
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

struct cmd {
	int	type;
};

//Parsing
struct cmd	*parsecmd(char *str);
struct cmd	*parseline(char **pstr, char *estr);
struct cmd	*parsepipe(char **pstr, char *estr);
struct cmd	*parseredirs(char **pstr, char *estr, struct cmd *cmd);
struct cmd	*parseexec(char **pstr, char *estr);
//Utils
void	ft_error(char *str);
int		fork1(void);

#endif
