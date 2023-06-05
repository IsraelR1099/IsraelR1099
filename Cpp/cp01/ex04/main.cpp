/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:36:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/05 12:55:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>

static void	ft_check_line(std::string line, std::ofstream &outfile, char *s1, char *s2)
{
	int		len;
	int		len_ptr;
	char	*eptr;
	char	*ptr;

	len = std::string(s1).length();
	ptr = const_cast<char*>(line.c_str());
	len_ptr = strlen(ptr);
	eptr = ptr + len_ptr;
	while (*ptr)
	{
		if (strncmp(ptr, s1, len) == 0)
		{
			outfile << s2;
			if (ptr + len < eptr)
			{
				ptr = ptr + len;
				continue ;
			}
			else
				break ;
		}
		else
			outfile << *ptr;
		ptr++;
	}
}

static void	ft_replace(char **str, std::ifstream &file)
{
	std::string		line;
	std::ofstream	outfile;
	std::string		name;

	name = str[1];
	name += ".replace";
	outfile.open(name);
	if (!outfile.is_open())
	{
		std::cout << "El archivo no se pudo abrir" << std::endl;
		exit (EXIT_FAILURE);
	}
	while (std::getline(file, line))
	{
		ft_check_line(line, outfile, str[2], str[3]);
		outfile << '\n';
	}
	outfile.close();
}

int	main(int counter, char **str)
{
	std::string	linea;

	if (counter == 4)
	{
		std::ifstream	fich(str[1]);
		if (!fich.is_open())
		{
			std::cout << "Error al abrir: " << str[1] << std::endl;
			exit (EXIT_FAILURE);
		}
		ft_replace(str, fich);
	}
	else
		std::cout << "Numero de argumentos invalido" << std::endl;
	return (0);
}

