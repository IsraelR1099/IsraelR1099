/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/03 11:33:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_object	*ft_build_sphere(t_object *obj, char *ftoken, char *eftoken)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(*sphere));
	if (!sphere)
		return (NULL);
	ft_memset(sphere, 0, sizeof(*sphere));
	sphere->type = sp;
	sphere->x = ft_coord(&ftoken, eftoken);
	sphere->y = ft_coord(&ftoken, eftoken);
	sphere->z = ft_coord(&ftoken, eftoken);
	sphere->diameter = ft_diameter(&ftoken, eftoken);
	sphere->r = ft_color(&ftoken, eftoken);
	sphere->g = ft_color(&ftoken, eftoken);
	sphere->b = ft_color(&ftoken, eftoken);
	sphere->r /= 255;
	sphere->g /= 255;
	sphere->b /= 255;
	if (ft_leftovers(ftoken, eftoken) < 0)
		exit (ft_error("leftovers sphere", -1));
	sphere->obj = obj;
	return ((t_object *)sphere);
}

t_object	*ft_build_plane(t_object *obj, char *ftoken, char *eftoken)
{
	t_plane	*plane;

	plane = malloc(sizeof(*plane));
	if (!plane)
		return (NULL);
	ft_memset(plane, 0, sizeof(*plane));
	plane->type = pl;
	plane->x = ft_coord(&ftoken, eftoken);
	plane->y = ft_coord(&ftoken, eftoken);
	plane->z = ft_coord(&ftoken, eftoken);
	plane->x_normal = ft_normal(&ftoken, eftoken);
	plane->y_normal = ft_normal(&ftoken, eftoken);
	plane->z_normal = ft_normal(&ftoken, eftoken);
	plane->r = ft_color(&ftoken, eftoken);
	plane->g = ft_color(&ftoken, eftoken);
	plane->b = ft_color(&ftoken, eftoken);
	plane->r /= 255;
	plane->g /= 255;
	plane->b /= 255;
	if (ft_leftovers(ftoken, eftoken) < 0)
		exit (ft_error("leftovers plane", -1));
	plane->obj = obj;
	return ((t_object *)plane);
}

t_object	*ft_build_cylinder(t_object *obj, char *ftoken, char *eftoken)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(*cylinder));
	if (!cylinder)
		return (NULL);
	ft_memset(cylinder, 0, sizeof(*cylinder));
	cylinder->type = cy;
	cylinder->x = ft_coord(&ftoken, eftoken);
	cylinder->y = ft_coord(&ftoken, eftoken);
	cylinder->z = ft_coord(&ftoken, eftoken);
	cylinder->x_normal = ft_normal(&ftoken, eftoken);
	cylinder->y_normal = ft_normal(&ftoken, eftoken);
	cylinder->z_normal = ft_normal(&ftoken, eftoken);
	cylinder->diameter = ft_diameter(&ftoken, eftoken);
	cylinder->height = ft_diameter(&ftoken, eftoken);
	cylinder->r = ft_color(&ftoken, eftoken);
	cylinder->g = ft_color(&ftoken, eftoken);
	cylinder->b = ft_color(&ftoken, eftoken);
	cylinder->r /= 255;
	cylinder->g /= 255;
	cylinder->b /= 255;
	if (ft_leftovers(ftoken, eftoken) < 0)
		exit (ft_error("leftovers cylinder", -1));
	cylinder->obj = obj;
	return ((t_object *)cylinder);
}

t_object	*ft_build_disk(t_object *obj, char *ftoken, char *eftoken)
{
	t_disk	*disk;

	disk = malloc(sizeof(*disk));
	if (!disk)
		return (NULL);
	ft_memset(disk, 0, sizeof(*disk));
	disk->type = di;
	disk->x = ft_coord(&ftoken, eftoken);
	disk->y = ft_coord(&ftoken, eftoken);
	disk->z = ft_coord(&ftoken, eftoken);
	disk->x_normal = ft_normal(&ftoken, eftoken);
	disk->y_normal = ft_normal(&ftoken, eftoken);
	disk->z_normal = ft_normal(&ftoken, eftoken);
	disk->radius = ft_diameter(&ftoken, eftoken);
	disk->r = ft_color(&ftoken, eftoken);
	disk->g = ft_color(&ftoken, eftoken);
	disk->b = ft_color(&ftoken, eftoken);
	disk->r /= 255;
	disk->g /= 255;
	disk->b /= 255;
	if (ft_leftovers(ftoken, eftoken) < 0)
		exit (ft_error("leftovers disk", -1));
	disk->obj = obj;
	return ((t_object *)disk);
}
