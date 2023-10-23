/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:49:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/23 12:13:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

Server::Server(void) : m_g_run_server(false), m_port(6667), m_password("default")
{
}

Server::Server(char **argv)
{
	m_port = atoi(argv[1]);
	if (m_port < 1024 || m_port > 65535)
	{
		std::string error(argv[1]);
		throw Server::BadFormat("Bad port: " + error);
	}
	m_password = argv[2];
	m_g_run_server = true;
}

Server::~Server(void)
{
}
