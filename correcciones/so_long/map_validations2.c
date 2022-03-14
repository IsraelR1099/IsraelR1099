/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_surronded_by_walls(char *map_info, t_mlx *mlx)
{
	if (!map_is_surrounded_be_walls(map_info, mlx))
	{
		free(map_info);
		free(mlx);
		write(2, "Error\nmap not surrounded be walls", 33);
		exit(0);
	}
}

int	map_is_surrounded_be_walls(char *map_info, t_mlx *mlx)
{
	int	count;
	int	linecount;

	count = 0;
	linecount = 0;
	while (map_info[count] != '\0')
	{
		if (map_info[count] == '\n')
		{
			if (map_info[count] == '\n' && (map_info[count - 1] != '1'
					|| map_info[count + 1] != '1'))
				return (0);
			count++;
			linecount++;
		}
		else
		{
			if (map_info[count] != '1' && (linecount == 0
					|| linecount == mlx->map_height -1))
				return (0);
			count++;
		}
	}
	return (1);
}
