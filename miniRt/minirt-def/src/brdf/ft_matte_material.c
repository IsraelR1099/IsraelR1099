/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matte_material.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:53:41 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 11:40:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"

t_rgb	ft_f_matte(t_shaderec *shade, double dotwi)
{
	t_rgb	f;
	t_rgb	f_diffuse;

	f_diffuse = ft_f_diffuse(shade, shade->colour);
	f = ft_rgb_scalar_product(f_diffuse, dotwi);
	return (f);
}
