/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:26:41 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/27 09:47:58 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

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
