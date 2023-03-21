/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:26:19 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 10:28:36 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	ft_set_world(t_ambient *amb, t_object *obj, t_world *world)
{
	world->camera = ft_build_camera(amb);
	world->amb = amb;
	world->obj = obj;
}
