/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx_pxput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:33 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/20 09:54:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "../../mlx/mlx.h"

void	ft_my_mlx_pxput(t_window *mlx, int x, int y, int colour)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->ll + x *(mlx->b / 8));
	*(unsigned int *)dst = colour;
}
