/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:38:57 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/03 14:04:56 by irifarac         ###   ########.fr       */
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
	struct t_list	*next;
}	t_nbr;

int	ft_checker(char **str, int counter);
int	ft_not_nbr(char c);
int	ft_dup(char **str, int counter);
int	ft_intdup(int *nbrs, int counter);

#endif
