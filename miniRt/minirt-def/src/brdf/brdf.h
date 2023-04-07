/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:26 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 13:13:43 by irifarac         ###   ########.fr       */
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

t_rgb		ft_brdf(t_rgb lights[2], t_shaderec *shade, t_vector3d dir[2],
				double dotwi);
t_rgb		ft_rho(t_shaderec *shade, t_rgb color);
t_rgb		ft_f_diffuse(t_shaderec *shade, t_rgb material_color);
t_rgb		ft_f_specular(t_shaderec *shade, t_vector3d dir[2],
				t_rgb point_light, double dotwi);
t_rgb		ft_f_phong(t_shaderec *shade, t_vector3d dir[2],
				t_rgb point_light, double dotwi);
t_rgb		ft_f_matte(t_shaderec *shade, double dotwi);

//Utils
t_vector3d	ft_product(t_shaderec *shade, double dotwi);
#endif
