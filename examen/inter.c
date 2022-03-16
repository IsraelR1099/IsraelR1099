/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:53:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/15 18:01:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_check(char *s1, char ch, int position)
{
	int	counter;

	counter = 0;
	while (counter < position)
	{
		if (s1[counter] == ch)
			return (0);
		counter++;
	}
	return (1);
}

void	ft_iter(char *s1, char *s2)
{
	size_t	position;
	size_t	position2;

	position = 0;
	while (s1[position])
	{
		if (ft_check(s1, s1[position], position))
		{
			position2 = 0;
			while (s2[position2])
			{
				if (s2[position2] == s1[position])
				{
					write(1, &s1[position], 1);
					break;
				}
				position2++;
			}
		}
		position++;
	}
}

int	main(int argc, char **argv)
{
	if(argc == 3)
		ft_iter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
