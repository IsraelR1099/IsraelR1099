/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:09:09 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/26 12:29:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

# include "../color/rgbcolor.h"
# include "../maths/maths.h"
# include "../utilities/shaderec.h"

typedef struct s_light_ambient
{
	double		light_s;
	t_rgb		color;
//	t_vector3d	(*ft_get_dir)(t_light * light, t_shaderec * shade);
//	t_rgb		(*ft_light)(double light_s, t_rgb color);
}	t_light_ambient;

t_rgb		ft_light(double light_s, t_rgb color);
t_vector3d	ft_get_dir(t_light *light, t_shaderec *shade);
bool		ft_hit_shadow(t_ray ray, t_world *world, double t);
double		ft_hit_sphere(t_sphere *sphere, t_ray ray);
double		ft_hit_plane(t_plane *plane, t_ray ray);
double		ft_hit_disk(t_disk *disk, t_ray ray);
bool		ft_in_shadow(t_ray shadow_ray, t_shaderec *shade, t_light *light);
t_object	*ft_advance(t_object *tmp);

#endif
