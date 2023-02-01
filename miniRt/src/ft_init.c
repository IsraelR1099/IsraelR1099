
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:40:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

static int	ft_destroy(t_window *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (1);
}

static void	ft_print(t_ambient *amb, t_object *obj)
{
	int	i;
	int	j;
	t_alight	*alight;

	i = 0;
	alight = (t_alight *)amb;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			my_mlx_pxput(mlx, j, i, alight->)


void	ft_init(t_ambient *amb, t_object *obj)
{
	t_window	*mlx;

	mlx = (t_window *)malloc(sizeof(*mlx));
	if (!mlx)
		exit(ft_error("Malloc error", 0));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "miniRT");
	ft_print(amb, obj);
	mlx_hook(mlx->mlx_win, 17, 0, ft_destroy, mlx);
	mlx_loop(mlx->mlx);
	(void)amb;
	(void)obj;
}
