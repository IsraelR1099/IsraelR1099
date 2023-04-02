/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbcolor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:01:51 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/31 13:57:30 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBCOLOR_H
# define RGBCOLOR_H

typedef struct s_rgbcolor
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

t_rgb	ft_rgb_scalar_product(t_rgb color, double scalar);
#endif
