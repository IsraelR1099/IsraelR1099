/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:38:57 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/16 13:40:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct	t_list
{
	int				data;
	int				index;
	struct t_list	*next;
}	t_nbr;

int		ft_checker(char **str, int counter);
int		ft_not_nbr(char c);
int		ft_dup(char **str, int counter);
int		ft_intdup(long *nbrs, int counter);
int		ft_max_nbr(t_nbr *head);
int		ft_min_nbr(t_nbr *head);
t_nbr	*ft_createlist(int nbr_nodes);
void	ft_update_index(t_nbr *head);
void	ft_sort_lst(t_nbr **head, int counter);
void	ft_sort_3(t_nbr **head);
void	ft_sort_4(t_nbr **head, t_nbr **head_b);
void	ft_sort_5(t_nbr **head, t_nbr **head_b);
void	ft_rra(t_nbr **head);
void	ft_sa(t_nbr **head);
void	ft_ra(t_nbr **head);
void	ft_pb(t_nbr **head, t_nbr **head_b);
void	ft_pa(t_nbr **head, t_nbr **head_b);
void	ft_write(int max, int min);
void	ft_deallocation(t_nbr **head);

#endif
