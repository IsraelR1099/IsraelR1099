/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:26:41 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/24 20:15:15 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

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
