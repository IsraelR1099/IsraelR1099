/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:36:00 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

float	ft_ratio(char **ftoken, char *eftoken)
{
	float	ret;
	char	*tmp;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_fatoi(&tmp);
	*ftoken = tmp;
	if (ret == -1 || ret > 1 || ret < 0)
		exit(ft_error("Wrong ratio", -1));
	return (ret);
}

int	ft_color(char **ftoken, char *eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_atoi(&tmp);
	if (*tmp == ',')
		tmp++;
	*ftoken = tmp;
	if (ret < 0 || ret > 255)
		exit(ft_error("Wrong color value", -1));
	return (ret);
}

float	ft_coord(char **ftoken, char *eftoken)
{
	char	*tmp;
	float	ret;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	else if (ft_compare(tmp, "sp") || ft_compare(tmp, "pl")
			|| ft_compare(tmp, "cy"))
		tmp += 2;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_fatoi(&tmp);
	if (*tmp == ',')
		tmp++;
	*ftoken = tmp;
//	if (ret == 1)
//		exit(ft_error("Wrong coordinates", -1));
	return (ret);
}

float	ft_normal(char **ftoken, char *eftoken)
{
	char	*tmp;
	float	ret;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_fatoi(&tmp);
	if (*tmp == ',')
		tmp++;
	*ftoken = tmp;
	if (ret < -1 || ret > 1)
		exit(ft_error("Wrong normal", -1));
	return (ret);
}

int	ft_fov(char **ftoken, char *eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_atoi(&tmp);
	*ftoken = tmp;
	if (ret < 0 || ret > 180)
		exit(ft_error("Wrong fov", -1));
	return (ret);
}
