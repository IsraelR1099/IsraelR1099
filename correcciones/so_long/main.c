/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*print_hero(t_mlx *mlx)
{
	load_basic_hero_images(mlx);
	load_basic_hero_images2(mlx);
	load_sprites_images_right(mlx);
	load_sprites_images_left(mlx);
	load_sprites_images_up(mlx);
	load_sprites_images_down(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->hero->img[0].img_ptr,
		mlx->hero->pos_x, mlx->hero->pos_y);
	return (mlx->hero->img);
}

void	count_another_move(t_mlx *mlx)
{
	if (mlx->hero->alive)
	{
		mlx->num_moves++;
		write(1, "Num Moves:", 10);
		ft_putnbr_fd(mlx->num_moves, 1);
		write(1, "\n", 1);
	}
}

int	can_move_to(int x, int y, t_mlx *mlx)
{
	if (mlx->map[x / 26][y / 26] == '0')
		return (1);
	else if (mlx->map[x / 26][y / 26] == '1')
	{
		return (0);
	}
	else if (mlx->map[x / 26][y / 26] == 'C')
	{
		mlx->map[x / 26][y / 26] = '0';
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->img[0].img_ptr, (x / 26) * 26, (y / 26) * 26);
		mlx->num_collectables--;
		if (mlx->num_collectables == 0)
			show_exit_door(mlx);
	}
	else if (mlx->map[x / 26][y / 26] == 'E' && mlx->num_collectables == 0)
	{
		show_you_win(mlx);
		mlx->hero->alive = 0;
	}
	return (1);
}

int	render(t_mlx *mlx)
{
	int	count;

	count = 0;
	if (!mlx->hero->alive)
		return (0);
	move_hero(mlx);
	return (1);
}

int	main(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	init_mlx_object(mlx);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->map = parse_initial_map(mlx);
	init_map_images(mlx);
	init_items_images(mlx);
	mlx->hero = init_hero(mlx);
	mlx->win = mlx_new_window(mlx->mlx_ptr, mlx->map_width * 26,
			(mlx->map_height * 26), "Bomberman hates MinilibX");
	print_initial_map(mlx->map_height, mlx->map_width, mlx);
	mlx->hero->img = print_hero(mlx);
	mlx_hook(mlx->win, 2, 0, input, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &render, mlx);
	mlx_hook(mlx->win, 17, 0, &exit_game, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
