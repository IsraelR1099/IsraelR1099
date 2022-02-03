/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/03 14:13:36 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char const *s, char c);
{
	unsigned int	i;
	unsigned int	counter;
	char	*ptr;

	i = 0;
	counter = 0;
	ptr = ft_strchr(s, c);
	while (str[i])
	{
		while (ptr != NULL)
		{
			ptr = ft_strchr(s, c);
			counter++;
		}
		i++;
	}
	return (counter + 1);


char	**ft_split(char const *s, char c)
{
	int	position;
	char	**ptr;
	int	start;

	ptr = malloc(sizeof(char *) * (ft_counter(s, c) + 1));

	return (ptr);
}
