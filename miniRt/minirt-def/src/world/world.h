/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:00:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/05 10:18:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../cameras/cameras.h"
# include "../window/window.h"
# include "../world/world.h"
# include "viewplane.h"

typedef struct s_world
{
	t_cameras	*camera;
	t_window	*mlx;
	t_object	*obj;
	t_ambient	*amb;
	t_vp		vp;
	t_light		**lights;
}	t_world;

void	ft_set_world(t_ambient *amb, t_object *obj, t_world *world);
void	ft_set_init(t_light **lights, t_ambient *amb);
int		ft_count_light(t_ambient *amb);
#endif
