/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:22:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/12 18:32:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_window;

//Errors
int	ft_error(char **str);
//Utils
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *str1, const char *str2);

#endif
