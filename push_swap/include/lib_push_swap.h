/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:38:57 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/22 10:21:59 by irifarac         ###   ########.fr       */
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

typedef struct t_list
{
	int				data;
	int				index;
	int				priority;
	int				positive;
	struct t_list	*next;
}	t_nbr;

int		ft_checker(char **str, int counter);
int		ft_check_sort(t_nbr **head, int counter);
int		ft_max_nbr(t_nbr *head);
int		ft_min_nbr(t_nbr *head);
int		ft_groups(int counter);
int		ft_max_value(t_nbr **head);
int		ft_condition_pb(t_nbr **head);
int		*ft_ini(t_nbr **head, int nbr);
int		ft_slst(t_nbr **head);
int		ft_pcheck(t_nbr **head);
int		ft_is_sort(t_nbr **head, int counter);
int		ft_best_way(t_nbr **head, int group, int counter);
int		ft_phase1(t_nbr **head, t_nbr **head_b, int counter);
int		ft_phase2(t_nbr **head, t_nbr **head_b, int counter);
int		ft_phase3(t_nbr **head, t_nbr **head_b, int counter);
int		ft_times(t_nbr **head, t_nbr **head_b);
int		ft_times_noprio(t_nbr **head, t_nbr **head_b);
int		ft_check_pos(t_nbr **head, int counter, int group);
int		ft_no_valid(char **str, int counter);
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
void	ft_inversions(t_nbr **head, t_nbr **head_b);
void	ft_pass_positive(t_nbr **head, int counter);
void	ft_send(t_nbr **head, t_nbr **head_b, int counter, int group);
void	ft_error(void);
void	ft_check_pb(t_nbr **head, t_nbr **head_b);
void	ft_check_rra(t_nbr **head, t_nbr **head_b);
void	ft_condition_send(t_nbr **head, t_nbr **head_b);

#endif
