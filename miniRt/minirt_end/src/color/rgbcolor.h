/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbcolor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:01:51 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/06 10:23:40 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBCOLOR_H
# define RGBCOLOR_H

# include <stdio.h>

typedef struct s_rgbcolor
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

t_rgb	ft_rgb_scalar_product(t_rgb color, double scalar);
t_rgb	ft_rgb_sum(t_rgb first, t_rgb second);
t_rgb	ft_max_to_one(t_rgb light_color);
t_rgb	*ft_clamp_to_color(t_rgb *light_color);
t_rgb	ft_rgb_product_vect(t_rgb first, t_rgb second);
t_rgb	ft_rgb_division(t_rgb up, double scalar);
#endif
