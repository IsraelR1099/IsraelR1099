/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:36:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/10 13:21:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	ft_check_sphere(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	t_sphere	**sphere;

	printf("antes\n");
	sphere = (t_sphere **)ft_find_lst_obj(obj, sp);
	printf("sphere one x %f, y %f, z %f\n", sphere[0]->x, sphere[0]->y, sphere[0]->z);
	printf("sphere two x %f, y %f, z %f\n", sphere[1]->x, sphere[1]->y, sphere[1]->z);
	exit (0);
	if (ft_inter_sphere(amb, sphere, ray_dir))
		return (sp);
	return (0);
}

int	ft_intersects(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	int	ret;

	printf("entro intersects\n");
	if (ft_check_sphere(amb, obj, ray_dir) == sp)
		ret = sp;
//	if (ft_inter_sphere(amb, obj, ray_dir))
//		ret = sp;
	else if (ft_inter_plane(amb, obj, ray_dir))
		ret = pl;
	//else if (ft_inter_cyl(amb, ray_dir))
	//	ret = cyl;
	else
		ret = A;
	return (ret);
}
