/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:56:12 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/06 13:59:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERAS_H
# define CAMERAS_H

# include "../parser/parser.h"
# include "../../include/miniRT.h"

typedef struct s_cameras
{
	t_point3d	eye;
	t_point3d	lookat;
	t_vector3d	right;
	t_vector3d	up;
	t_vector3d	forward;
}	t_cameras;

#endif
