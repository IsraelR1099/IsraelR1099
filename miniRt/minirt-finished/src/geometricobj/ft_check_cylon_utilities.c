/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rf_cylon_utilites.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:12:28 by msoler-e          #+#    #+#             */
/*   Updated: 2023/05/12 12:23:12 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"
#define EPSILON 1e-4

void	ft_cyl_center_normal_rad(t_cylinder cylon, t_vector3d *cyl_normal,
t_vector3d *cyl_center)
{
	cyl_center->x = cylon.x;
	cyl_center->y = cylon.y;
	cyl_center->z = cylon.z;
	cyl_normal->x = cylon.x_normal;
	cyl_normal->y = cylon.y_normal;
	cyl_normal->z = cylon.z_normal;
}

void	ft_ray_origin(t_ray ray, t_vector3d *ray_orig)
{
	ray_orig->x = ray.origin.x;
	ray_orig->y = ray.origin.y;
	ray_orig->z = ray.origin.z;
}

double	distance(const t_vector3d p1, const t_vector3d p2)
{
	return (sqrt(pow(p2.x - p1.x, 2)
			+ pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2)));
}

double	solve_plane(t_vector3d o, t_vector3d d, t_vector3d p_p, t_vector3d p_nv)
{
	double	x;
	double	denom;

	denom = ft_dot_product_vect(p_nv, d);
	if (denom == 0)
		return (-1);
	x = (ft_dot_product_vect(p_nv, ft_rest_vect(p_p, o))) / denom;
	if (x > EPSILON)
		return (x);
	else
		return (-1);
}

void	swap_doubles(double *a, double *b)
{
	double	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}
