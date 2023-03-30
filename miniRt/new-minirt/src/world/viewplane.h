/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewplane.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:31:14 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/24 10:58:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPLANE_H
# define VIEWPLANE_H

# include "world.h"
# include "../color/rgbcolor.h"

typedef struct s_viewplane
{
	int		num_samples;
	t_rgb	color;
}	t_vp;

#endif
