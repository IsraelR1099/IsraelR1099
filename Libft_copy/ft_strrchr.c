/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:19:54 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/17 12:38:13 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int ch)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		position++;
	}
	while (position >= 0)
	{
		if (str[position] == ch)
		{
			return (&str[position]);
		}
		position--;
	}
	return (0);
}
