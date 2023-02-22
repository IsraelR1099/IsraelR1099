/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:21:02 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/22 11:11:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	ft_apply_transformsphere(t_sphere *sphere, t_4dvector *look_at)
{
	printf("sphere x es %f\n", sphere->x);
	sphere->x = look_at[0].x * sphere->x + look_at[0].y * sphere->y + look_at[0].z * sphere->z;
	sphere->y = look_at[1].x * sphere->x + look_at[1].y * sphere->y + look_at[1].z * sphere->z;
	sphere->z = look_at[2].x * sphere->x + look_at[2].y * sphere->y + look_at[2].z * sphere->z;
	printf("sphere x despues es %f\n", sphere->x);
}

void	ft_apply_transformplane(t_plane *plane, t_4dvector *look_at)
{
	plane->x = look_at[0].x * plane->x + look_at[0].y * plane->y + look_at[0].z * plane->z;
	plane->y = look_at[1].x * plane->x + look_at[1].y * plane->y + look_at[1].z * plane->z;
	plane->z = look_at[2].x * plane->x + look_at[2].y * plane->y + look_at[2].z * plane->z;
}

void	ft_apply_transformcyl(t_cylinder *cyl, t_4dvector *look_at)
{
	cyl->x = look_at[0].x * cyl->x + look_at[0].y * cyl->y + look_at[0].z * cyl->z;
	cyl->y = look_at[1].x * cyl->x + look_at[1].y * cyl->y + look_at[1].z * cyl->z;
	cyl->z = look_at[2].x * cyl->x + look_at[2].y * cyl->y + look_at[2].z * cyl->z;
}

void	ft_obj_transform(t_ambient *amb, t_object *obj)
{
	t_4dvector	look_at[4];
	t_object	*tmp;

	tmp = obj;
	ft_translation(amb, look_at);
	while (tmp)
	{
		if (tmp->type == sp)
			ft_apply_transformsphere((t_sphere *)tmp, look_at);
		else if (tmp->type == pl)
			ft_apply_transformplane((t_plane *)tmp, look_at);
		else if (tmp->type == cy)
			ft_apply_transformcyl((t_cylinder *)tmp, look_at);
		if (tmp->type == 3)
			tmp = ft_util_find(tmp, 3);
		else if (tmp->type == 4)
			tmp = ft_util_find(tmp, 4);
		else if (tmp->type == 5)
			tmp = ft_util_find(tmp, 5);
		else
			break ;
	}
}
