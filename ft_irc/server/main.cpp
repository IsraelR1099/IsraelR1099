/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:26:41 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/26 15:53:27 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Server.hpp"

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		try
		{
			Server	server(argv);

			server.setServer();
            server.launchServer();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Correct usage is: ./ircserv [address] [port]" << std::endl;
	return (0);
}
