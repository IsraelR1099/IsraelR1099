/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samplers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:00:08 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 12:10:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLER_H
# define SAMPLER_H

# include "../maths/maths.h"
# include "../window/window.h"
# include "../world/world.h"
# include "../tracers/tracer.h"
# include "../utilities/rgbcolor.h"

size_t	ft_samplers(t_world *world, t_ray *ray, double x, double y);

#endif
