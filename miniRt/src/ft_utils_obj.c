/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:02:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/23 13:46:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	ft_search(char **str, char *estr, char *tokens, int len)
{
	char	*tmp;

	tmp = *str;
	while (tmp < estr)
	{
		while (len)
		{




int	ft_find_obj(char **str, char *estr, char *tokens, int len)
{
	char	*tmp;

	tmp = *str;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*str = tmp;
	return (ft_search(str, estr, tokens, len));
}
