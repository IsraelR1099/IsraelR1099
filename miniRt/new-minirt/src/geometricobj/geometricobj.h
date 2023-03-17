/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometricobj.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:27:51 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 12:27:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRICOBJ_H
# define GEOMETRICOBJ_H

# include <math.h>
# include "../parser/parser.h"
# include "../maths/maths.h"
# include "../cameras/cameras.h"

double	ft_check_sphere(t_cameras *camera, t_sphere *sphere, t_ray *ray);
double	ft_check_plane(t_cameras *camera, t_plane *plnae, t_ray *ray);

#endif
