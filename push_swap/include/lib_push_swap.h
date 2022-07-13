/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:38:57 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/13 12:54:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct	t_list
{
	int				data;
	int				index;
	int				priority;
	struct t_list	*next;
}	t_nbr;

int		ft_checker(char **str, int counter);
int		ft_check_sort(t_nbr **head, int counter);
int		ft_not_nbr(char c);
int		ft_dup(char **str, int counter);
int		ft_intdup(long *nbrs, int counter);
int		ft_max_nbr(t_nbr *head);
int		ft_min_nbr(t_nbr *head);
int		ft_size(t_nbr *head);
int		ft_groups(int counter);
int		ft_max_value(t_nbr **head);
int		ft_condition_rra(t_nbr **head, int counter);
int		ft_condition_rrb(t_nbr **head_b);
int		ft_condition_sa(t_nbr **head);
int		ft_condition_sb(t_nbr **head_b);
int		ft_condition_ra(t_nbr **head);
int		ft_condition_rb(t_nbr **head_b);
int		ft_condition_pb(t_nbr **head);
int		ft_condition_pa(t_nbr **head, t_nbr **head_b, int counter);
int		*ft_ini(t_nbr **head, int nbr);
int		ft_slst(t_nbr **head);
int		ft_pcheck(t_nbr **head);
int		ft_diff_up(t_nbr **head, int nbr);
int		ft_diff_down(t_nbr **head, int nbr);
int		ft_is_sort(t_nbr **head, int counter);
int		ft_go_check(t_nbr **head);
t_nbr	*ft_createlist(int nbr_nodes);
t_nbr	*ft_lastnode(t_nbr *tmp);
void	ft_update_index(t_nbr *head);
void	ft_utilsort_m4(t_nbr **head, t_nbr **head_b, int counter);
void	ft_utilsort_min5(t_nbr **head, t_nbr **head_b, int counter);
void	ft_utilsort_max5(t_nbr **head, t_nbr **head_b, int counter);
void	ft_utilsort_max4(t_nbr **head, t_nbr **head_b, int counter);
void	ft_sort_lst(t_nbr **head, int counter);
void	ft_sort_3(t_nbr **head, int counter);
void	ft_sort_4(t_nbr **head, t_nbr **head_b, int counter);
void	ft_sort_5(t_nbr **head, t_nbr **head_b, int counter);
void	ft_algorithm(t_nbr **head, t_nbr **head_b, int counter);
void	ft_rra(t_nbr **head);
void	ft_sa(t_nbr **head);
void	ft_ra(t_nbr **head);
void	ft_pb(t_nbr **head, t_nbr **head_b);
void	ft_pa(t_nbr **head, t_nbr **head_b);
void	ft_rrb(t_nbr **head_b);
void	ft_sb(t_nbr **head_b);
void	ft_rb(t_nbr **head_b);
void	ft_ss(t_nbr **head, t_nbr **head_b);
void	ft_rr(t_nbr **head, t_nbr **head_b);
void	ft_rrr(t_nbr **head, t_nbr **head_b);
void	ft_write(int max, int min);
void	ft_deallocation(t_nbr **head);
void	ft_priority(t_nbr **head, int counter);
void	ft_update_priority(t_nbr **head, int *max_group);
void	ft_apply_pb(t_nbr **head, t_nbr **head_b, t_nbr **tmp);
void	ft_apply_rra(t_nbr **head, t_nbr **tmp);
void	ft_apply_ss(t_nbr **head, t_nbr **head_b, t_nbr **tmp, t_nbr **tmp_b);
void	ft_apply_sa(t_nbr **head, t_nbr **tmp);

#endif
