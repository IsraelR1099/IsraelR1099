/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:56:32 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/03 13:30:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../src/parser/parser.h"
# include "../src/window/window.h"
# include "../src/world/world.h"
# include "../src/cameras/cameras.h"

# define WIDTH 1080
# define HEIGHT 720

void		ft_init(t_ambient *amb, t_object *obj);
void		ft_render(t_world *world);
t_ambient	*ft_find_amb(t_ambient *amb, int type);

//mlx events
int			key_event(int button, t_world *world);
int			ft_destroy(t_world *world);
//Utils
t_object	*ft_free_advance(t_object *tmp);
t_ambient	*ft_free_advance_amb(t_ambient *tmp);
#endif
