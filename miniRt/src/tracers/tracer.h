/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:59:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 12:12:25 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# include "../utilities/shaderec.h"
# include "../maths/maths.h"
# include "../utilities/rgbcolor.h"
# include "../world/world.h"

t_rgb	ft_trace_ray(t_world *world, t_ray *ray);

#endif
