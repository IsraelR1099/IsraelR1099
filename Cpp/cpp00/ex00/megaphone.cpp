/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:39:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/12 13:17:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_print(char str, int where)
{
	char	c;

	c = toupper(str);
	if (where == 1)
		std::cout << c << std::endl;
	else
		std::cout << c;
}

int	main(int argc, char **argv)
{
	int	i;
	int	where;

	i = 1;
	where = 0;
	if (i == argc)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (i < argc)
	{
		if (i == (argc - 1))
		{
			for (int x=0; x<(int)strlen(argv[i]); x++)
			{
				if (x == (int)strlen(argv[i] + 1))
					where = 1;
				ft_print(argv[i][x], where);

			}
		}
		else
		{
			for (int x=0; x<(int)strlen(argv[i]); x++)
				ft_print(argv[i][x], 0);
			std::cout << ' ';
		}
		i++;
	}
	return (0);
}
