/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:26 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/06 09:43:54 by irifarac         ###   ########.fr       */
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

t_rgb	ft_brdf(t_rgb lights[2], t_shaderec *shade, t_vector3d dir[2], double dotwi);
t_rgb	ft_rho(t_shaderec *shade, t_rgb color); // reflectance or albedo function kd * cd
#endif
