/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:49:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/23 11:50:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

Server::Server(void) : m_g_run_server(FALSE), m_port(6667), m_password("default")
{
}

Server::Server(char **argv)
{
	unsigned short	port;

	port = atoi(argv[1]);
	if (port < 1024 || port > 65535)
	{
		std::string error(argv[1]);
		throw Server::BadFormat("Bad port: " + error);
	}
	m_password = argv[2];
}

~Server::Server(void)
{
}
