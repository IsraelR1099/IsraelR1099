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

int	ft_intersects(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	int	ret;
	int	color;

	color = ft_inter_sphere(amb, obj, ray_dir);
	if (color != 0)
		return (sp);
	else if (ft_inter_plane(amb, obj, ray_dir))
		ret = pl;
	//else if (ft_inter_cyl(amb, ray_dir))
	//	ret = cyl;
	else
		ret = A;
	return (ret);
}
