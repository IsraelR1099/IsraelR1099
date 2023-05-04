/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:22:17 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/24 12:26:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

# include "../brdf/brdf.h"
# include "../maths/maths.h"
# include "../world/world.h"
# include "../utilities/shaderec.h"
# include "../lights/lights.h"
# include "../color/rgbcolor.h"
# include "../tracers/tracer.h"

typedef struct s_matte
{
	t_lambertian	*ambient_brdf;
	t_lambertian	*diffuse_brdf;
	t_rgb			(*ft_shade)(t_world * world, t_shaderec *shade);
}	t_matte;

t_rgb	ft_shade_phong(t_world *world, t_shaderec *shade);
t_rgb	ft_reflective_f(t_world *world, t_shaderec *shade, t_vector3d wo,
t_vector3d *wi);
t_rgb	ft_shade_reflective(t_world *world, t_shaderec *shade);
#endif
