/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/16 12:28:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

/*int	destroy(t_window *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (1);
}*/

static int	ft_len(int fd)
{
	int		nbr_bytes;
	int		len;
	char	tmp[BUFFER_SIZE + 1];

	len = 0;
	nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	while (nbr_bytes > 0)
	{
		tmp[nbr_bytes] = '\0';
		if (ft_strchr(tmp, '\n'))
			len++;
		nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	}
	return (len);
}

char	**ft_lines(char *str,int fd)
{
	char	**ret;
	int		i;
	int		len;

	len = ft_len(fd);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit(ft_error("Open error", -1));
	ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		exit(ft_error("Malloc error", -1));
	ret[0] = ft_get_next_line(fd);
	i = 1;
	while (len)
	{
		ret[i] = ft_get_next_line(fd);
		printf("str es %s\n", ret[i]);
		i++;
		len--;
	}
	ret[i] = NULL;
	return (ret);
}


int	main(int counter, char **str)
{
//	t_ambient	*test;
	int			fd;
	char	**test;
/*	t_window	*mlx;

	mlx = (t_window *)malloc(sizeof(t_window));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1080, 720, "Ejemplo");
	mlx_hook(mlx->mlx_win, 17,0, destroy, mlx);
	mlx_loop(mlx->mlx);*/
	if (counter == 2)
	{
		if (ft_check_error(str) >= 0)
		{
			fd = open(str[1], O_RDONLY);
			if (fd < 0)
				return (ft_error("Open error", -1));
			test = ft_lines(str[1], fd);
			int i = 0;
			while (i++ < 8)
				printf("str[%d] es %s\n", i, test[i]);
		}
	}
	else
		printf("Wrong number of arguments\n");
	return (0);
}
