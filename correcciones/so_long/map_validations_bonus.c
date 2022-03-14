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

/*

◦ The map must be closed/surrounded by walls, if not the program must return 
  an error.
◦ Map must have at least one exit, one collectible, and one starting position.
◦ You don’t need to check if there’s a valid path in the map.
◦ The map must be rectangular.
◦ You must be able to parse any kind of map, as long as it respects the rules 
  of the map.

If any misconfiguration of any kind is encountered in the file, the program must
exit properly and return "Error\n" followed by an explicit error message of your
choice.
*/

void	check_map_file_exist(char *map_info, t_mlx *mlx)
{
	if (!map_info)
	{
		free(mlx);
		write(2, "Error\nMap file no such file or directory", 40);
		exit(0);
	}
}

void	check_map_valid_height_and_width(char *map_info, t_mlx *mlx)
{
	if (map_lines_height(map_info) < 3)
	{
		free(map_info);
		free(mlx);
		write(2, "Error\nMap height is not valid", 29);
		exit(0);
	}
	if (map_lines_width(map_info) < 3)
	{
		free(map_info);
		free(mlx);
		write(2, "Error\nMap width is not valid", 29);
		exit(0);
	}	
}

void	check_map_is_rectangular(char *map_info, t_mlx *mlx)
{
	int	count_y;
	int	count_x;
	int	count;

	count = 0;
	count_y = 0;
	count_x = 0;
	while (count_y < mlx->map_height)
	{
		while (map_info[count] != '\n' && map_info[count] != '\0')
		{
			count++;
			count_x++;
		}
		if (count_x != mlx->map_width)
		{
			free(map_info);
			free(mlx);
			write(2, "Error\nMap is not rectangular", 28);
			exit(0);
		}
		count++;
		count_x = 0;
		count_y++;
	}
}

void	check_map_valid_chars(char *map_info, t_mlx *mlx)
{
	int	count;

	count = 0;
	while (map_info[count] != '\0')
	{
		if (map_info[count] == '0' || map_info[count] == '1'
			|| map_info[count] == 'C' || map_info[count] == 'E'
			|| map_info[count] == 'N' || map_info[count] == 'P'
			|| map_info[count] == '\n')
		{
			count++;
		}
		else
		{
			free(map_info);
			free(mlx);
			write(2, "Error\nInvalid characters in map", 32);
			exit(0);
		}
	}
}

void	check_map_needed_chars(char *map_info, t_mlx *mlx)
{
	int	count;
	int	count_p;
	int	count_e;
	int	count_c;

	count = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (map_info[count++] != '\0')
	{
		if (map_info[count - 1] == 'C')
			count_c++;
		if (map_info[count - 1] == 'P')
			count_p++;
		if (map_info[count - 1] == 'E')
			count_e++;
	}
	if (count_p == 0 || count_e == 0 || count_c == 0)
	{
		free(map_info);
		free(mlx);
		write(2, "Error\nNot C or P or E in map", 28);
		exit(0);
	}
}
