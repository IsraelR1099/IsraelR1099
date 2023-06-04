/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:36:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/04 20:52:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>

void	ft_change_out(char *s2, std::ofstream &outfile)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		outfile << s2[i];
		i++;
	}
}

void	ft_check_line(std::string line, std::ofstream &outfile, char *s1, char *s2)
{
	int				len;
	int				i;
	int				j;
	int				compare;

	len = std::string(s1).length();
	i = 0;
	std::cout << "len es : " << len << std::endl;
	//std::cout << "linea es: " << line << "len es: " << len << std::endl;
	while (line[i])
	{
	//	std::cout << "i principio: " << i << std::endl;
		if (line[i] == *s1)
		{
			compare = i;
			j = 0;
			while (line[compare] == s1[j] && s1[j] && j <= len)
			{
				std::cout << "entro" << std::endl;
				if (line[compare] != s1[j])
					break;
				compare++;
				j++;
			}
			std::cout << "compare es: " << compare << std::endl;
			if ((compare - 1) == len)
			{
				std::cout << "entro en compare" << std::endl;
				ft_change_out(s2, outfile);
				i = i + len;
				continue ;
			}
		}
	//	else
			outfile << line[i];
		//std::cout << "line i es: " << line[i] << " y i: " << i << std::endl;
		i++;
	}
}

void	ft_replace(char **str, std::ifstream &file)
{
	std::string		line;
	std::ofstream	outfile;

	outfile.open("output.replace");
	if (!outfile.is_open())
	{
		std::cout << "El archivo no se pudo abrir" << std::endl;
		exit (EXIT_FAILURE);
	}

	while (std::getline(file, line, ' '))
	{
		std::cout << "linea: " << line << std::endl;
		ft_check_line(line, outfile, str[2], str[3]);
		outfile << ' ';
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

