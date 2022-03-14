/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_initial_map(int map_height, int map_width, t_mlx *mlx)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	pos_y = 0;
	while (pos_y++ < map_height)
	{
		while (pos_x < map_width)
		{
			if (mlx->map[pos_x][pos_y - 1] == '0')
				parse_0_tile(mlx, pos_x, pos_y - 1);
			else if (mlx->map[pos_x][pos_y - 1] == '1')
				parse_1_tile(mlx, pos_x, pos_y - 1);
			else if (mlx->map[pos_x][pos_y - 1] == 'P')
				parse_p_tile(mlx, pos_x, pos_y - 1);
			else if (mlx->map[pos_x][pos_y - 1] == 'C')
				parse_c_tile(mlx, pos_x, pos_y - 1);
			else if (mlx->map[pos_x][pos_y - 1] == 'N')
				parse_n_tile(mlx, pos_x, pos_y);
			else if (mlx->map[pos_x][pos_y - 1] == 'E')
				parse_e_tile(mlx, pos_x, pos_y - 1);
			pos_x++;
		}
		pos_x = 0;
	}
}

void	fill_map_matrix(t_mlx *mlx, char *map_info)
{
	int		count2;
	int		count_y;
	int		count_x;

	count2 = 0;
	count_x = 0;
	count_y = 0;
	while (map_info[count2])
	{
		if (map_info[count2] != '\n')
		{
			mlx->map[count_x][count_y] = map_info[count2];
			count_x++;
		}
		else
		{
			count_y++;
			count_x = 0;
		}
		count2++;
	}	
}

char	**parse_initial_map(t_mlx *mlx)
{
	char	*map_info;
	int		count;

	count = 0;
	map_info = get_initial_map_info("maps/map_empty_bonus.ber");
	check_map_file_exist(map_info, mlx);
	mlx->map_height = map_lines_height(map_info);
	mlx->map_width = map_lines_width(map_info);
	check_map_valid_height_and_width(map_info, mlx);
	check_map_is_rectangular(map_info, mlx);
	check_map_valid_chars(map_info, mlx);
	check_map_surronded_by_walls(map_info, mlx);
	check_map_needed_chars(map_info, mlx);
	create_map_x_malloc(mlx);
	mlx->map[mlx->map_width] = NULL;
	while (count <= mlx->map_width)
	{
		mlx->map[count] = create_map_y_malloc(mlx, count);
		mlx->map[count][mlx->map_height] = '\0';
		mlx->map[count][mlx->map_height + 1] = '\0';
		count++;
	}
	fill_map_matrix(mlx, map_info);
	free(map_info);
	return (mlx->map);
}
