/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:59:38 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 20:00:41 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/libft.h"

typedef struct s_stacks
{
	int				value;
	struct s_stacks	*next;
}	t_stacks;

typedef struct s_meta_data
{
	int					size;
	int					moves;
	int					error;
	int					count;
	int					init;
	struct s_stacks		*first_a;
	struct s_stacks		*first_b;
}	t_meta_data;

char		*get_next_line(int fd);
char		*ft_substr_gnl(char *s, int start, int len, int *nl_len);
char		*ft_strjoin_gnl(char *s1, char *s2, int bytes, int *nl_len);
void		ft_swap_action(t_meta_data *meta, char ab);
void		ft_rotate_action(t_meta_data *meta, char ab);
void		ft_reverse_rotate_action(t_meta_data *meta, char ab);
void		ft_push_action(t_meta_data *meta, char ab);
int			ft_do_push(t_meta_data *meta, char ab);
int			ft_do_rotate(t_meta_data *meta, char ab);
int			ft_do_reverse_rotate(t_meta_data *meta, char ab);
int			ft_do_swap(t_meta_data *meta, char ab);
int			ft_get_command(t_meta_data *meta, char *line);
int			ft_clear_split(char **split);
int			ft_clear_all(t_meta_data *meta);
t_meta_data	*ft_meta_data_init(void);
int			ft_load_stack(char **input, t_meta_data *meta);
int			ft_send_to_atoi(char *str);
int			ft_check_solve(t_meta_data *meta);
int			ft_list_size(t_stacks *first_node);
int			ft_check_input_limits(char **input, t_meta_data *meta);
int			ft_check_error_solve(void);
void		ft_print_results(int msg, t_meta_data *meta);
int			ft_process_list(int argc, char *argv[], t_meta_data *meta);
void		ft_process_commands(int argc, t_meta_data *meta);
#endif
