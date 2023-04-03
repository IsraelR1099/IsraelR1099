/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:26 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/03 13:05:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRDF_H
# define BRDF_H

# include "../color/rgbcolor.h"
# include "../utilities/shaderec.h"
# include "../maths/maths.h"

typedef struct s_lambertian
{
	float	kd;
	t_rgb	color;
}	t_lambertian;

void	ft_brdf(t_rgb *total_light, t_shaderec *shade, t_rgb point_light, double dotwi);
#endif
