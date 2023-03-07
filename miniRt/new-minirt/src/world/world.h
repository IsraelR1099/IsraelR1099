/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:00:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/06 14:00:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../../include/miniRT.h"
# include "../cameras/cameras.h"
# include "../window/window.h"
# include "../world/world.h"

typedef struct s_world
{
	t_cameras	*camera;
	t_window	*mlx;
}	t_world;

void	ft_set_world(t_ambient *amb, t_world *world);
#endif
