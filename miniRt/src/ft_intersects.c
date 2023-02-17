/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:36:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/17 10:39:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/*int	ft_intersects(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	int	ret;
	int	color;

	ret = 0;
	color = ft_inter_sphere(amb, obj, ray_dir);
	if (color != 0)
		return (sp);
//	else if (ft_inter_plane(amb, obj, ray_dir))
//		ret = pl;
	//else if (ft_inter_cyl(amb, ray_dir))
	//	ret = cyl;
	else
		ret = A;
	return (ret);
}*/

int	ft_intersects(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	int			color;
	t_object	*tmp;
	double		distance_sph;
	double		distance_pla;
	t_sphere	*sphere;
	t_plane		*plane;

	tmp = obj;
	color = 0;
	while (tmp)
	{
		sphere = ft_ret_sphere(tmp, sp);
		if (!sphere)
			break ;
		plane = ft_ret_plane(tmp, pl);
		if (!sphere || !plane)
			break ;
		distance_sph = ft_distance_sphere(amb, sphere, ray_dir);
		distance_pla = ft_inter_plane(amb, plane, ray_dir);
		if (distance_sph != 0 && distance_pla != 0)
			printf("dist sphere %f, dist pla %f\n", distance_sph, distance_pla);
		else if (distance_sph < distance_pla)
			color = sp;
		else if (distance_pla < distance_sph)
			color = pl;
		tmp = ft_util_find(tmp, tmp->type);
	}
	return (color);
}

