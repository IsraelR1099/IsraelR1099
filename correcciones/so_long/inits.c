/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx_object(t_mlx *mlx)
{
	mlx->num_moves = 0;
	mlx->num_enemys = 0;
	mlx->num_collectables = 0;
}

t_hero	*init_hero(t_mlx *mlx)
{
	mlx->hero = create_hero_malloc(mlx);
	mlx->hero->img = create_hero_images_malloc(mlx);
	mlx->hero->pos_x = 0;
	mlx->hero->pos_y = 0;
	mlx->hero->collected = 0;
	mlx->hero->alive = 1;
	mlx->hero->direction = 0;
	mlx->hero->sp_time = 0;
	mlx->hero->sp_num = 0;
	return (mlx->hero);
}
