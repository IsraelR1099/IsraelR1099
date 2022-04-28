/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_imagen3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:47:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/27 13:21:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

# define	WIN_WIDTH	1220
# define	WIN_HEIGHT	720

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
}	t_mlx;


int	main(void)
{
	t_mlx	mlx; //Here I first create my struct that will contains all the "MLX stuff"
	int		count_w;
	int		count_h;

	count_h = -1;
	//First you need to call mlx_init and store its return value.
	mlx.mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	//One more time with mlx_new_image
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	/*
	 Now the important part :
	 mlx_get_data_addr will return a char* that is 4 times the (width * height) of your image.
	 Why so ? Let me explain : This char* will represent your image, pixel by pixel,
	 and the values of this array are the colors. That's why the array is 4 times bigger :
	 you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
	 But... it's not very convenient, right ? So here is my little trick : you cast
	 mlx_get_data_addr as an int* and store it in an int*.
	 This way, the array will have the exact same size as your window, and each index
	 will represent one complete color of a pixel !
	*/
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);
	/*
	 Now just a little example : here is a loop that will draw each pixels that
	 have an odd width in white and the ones that have an even width in black.
	*/
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if (count_w % 2)
				/*
				 As you can see here instead of using the mlx_put_pixel function
				 I just assign a color to each pixel one by one in the image,
				 and the image will be printed in one time at the end of the loop.
				 Now one thing to understand here is that you're working on a 1-dimensional
				 array, while your window is (obviously) 2-dimensional.
				 So, instead of having data[height][width] here you'll have the following
				 formula : [current height * max width + current width] (as you can see below)
				*/
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
			else
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
		}
	}
	//Now you just have to print the image using mlx_put_image_to_window !
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
