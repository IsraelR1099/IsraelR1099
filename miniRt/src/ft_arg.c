/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/22 15:08:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

float	ft_ratio(char **ftoken, char *eftoken)
{
	float	ret;
	char	*tmp;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	printf("ftoken ratio es %s\n", tmp);
	ret = ft_fatoi(tmp);
	printf("ret es %f\n", ret);
	if (ret == -1)
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
	ret = ft_atoi(*ftoken);
	if (ret < 0)
		exit(ft_error("Wrong color value", -1));
	return (ret);
}

float	ft_coord(char **ftoken, char *eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_fatoi(tmp);
	if (ret == 1)
		exit(ft_error("Wrong coordinates", -1));
	return (ret);
}

int	ft_normal(char **ftoken, char *eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *ftoken;
	if (ft_strchr("ACL", *tmp))
		tmp++;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_atoi(tmp);
	if (ret == -1)
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
	ret = ft_atoi(tmp);
	if (ret < 0)
		exit(ft_error("Wrong fov", -1));
	return (ret);
}


