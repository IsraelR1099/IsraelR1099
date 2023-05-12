/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samplers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:00:08 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 13:55:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLERS_H
# define SAMPLERS_H

# include "../maths/maths.h"
# include "../window/window.h"
# include "../world/world.h"
# include "../tracers/tracer.h"
# include "../color/rgbcolor.h"

size_t	ft_samplers(t_world *world, t_ray *ray, double c, double r);

#endif
