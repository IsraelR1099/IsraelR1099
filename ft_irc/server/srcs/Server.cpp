/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:49:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/01 10:38:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

Server::Server(void) : m_g_run_server(false), m_port(6667), m_password("default"), m_fd_server(0)
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
	if (m_password.empty())
	{
		std::string error(argv[2]);
		throw Server::BadFormat("Bad password: " + error);
	}
	m_g_run_server = true;
	std::cout << "passwd: " << m_password << std::endl;
	std::cout << "port: " << m_port << std::endl;
}

Server::~Server(void)
{
}

void	Server::setServer(void)
{
	int		rc;
	int		val;
	Channel	generalChannel("general");

	rc = 0;
	m_fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd_server < 0)
		throw Server::BadFormat("Socket() failed");
	else
		std::cout << "Socket succesfully created..." <<std::endl;
	val = 1;
	rc = setsockopt(m_fd_server, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	if (rc < 0)
		throw Server::BadFormat("setsockopt() failed");
	else
		std::cout << "setsockopt succesfully set..." << std::endl;

	memset(&_server, 0, sizeof(_server));
	_server.sin_family = AF_INET;
	_server.sin_port = htons(m_port);
	_server.sin_addr.s_addr = htonl(INADDR_ANY);
	rc = bind(m_fd_server, (struct sockaddr *)&_server, sizeof(_server));
	if (rc < 0)
		throw Server::BadFormat("bind() failed");
	else
		std::cout << "Socket succesfully binded" << std::endl;
	rc = listen(m_fd_server, 5);
	if (rc < 0)
		throw Server::BadFormat("listen() failed");
	else
		std::cout << "Server listening..." << std::endl;
	memset(m_fds, 0, sizeof(m_fds));
	m_fds[0].fd = m_fd_server;
	m_fds[0].events = POLLIN;
	_channels.insert(std::make_pair(0, generalChannel));
}

int Server::launchServer(void)
{
    int rc;
    int nfds;

    nfds = 1;
    while (m_g_run_server)
    {
        rc = poll(m_fds, nfds, -1);
		if (rc < 0)
            throw Server::ServerError("poll() failed");
        else if (rc == 0)
            throw Server::ServerError("poll() timed out");
        else
            std::cout << "poll() succesfully set..." << std::endl;
        for (int i = 0; i < nfds; i++)
        {
            if (m_fds[i].revents == 0)
                continue;
            if (m_fds[i].revents != POLLIN)
            {
                std::cerr << "Error! revents = " << m_fds[i].revents << std::endl;
                m_g_run_server = false;
                break;
            }
            if (m_fds[i].fd == m_fds[0].fd)
            {
                std::cout << "New client request" << std::endl;
				if (_acceptClient(nfds) < 0)
					throw Server::ServerError("accept() failed");
				else
					std::cout << "New client accept succesful..." << std::endl;
				nfds++;
			}
			else
			{
				std::cout << "Descriptor: " << m_fds[i].fd << " is readeable" << std::endl;
				_receiveClient(i);
			}
        }
		int	nClients;

		nClients =  0;
		std::map<int, Client>::iterator it;
		for (it = _clients.begin(); it != _clients.end(); it++)
			nClients++;
		std::cout << "Number of clients: " << nClients << std::endl;

		int	nChannels;

		nChannels = 0;
		std::map<int, Channel>::iterator it_ch;
		for (it_ch = _channels.begin(); it_ch != _channels.end(); it_ch++)
			nChannels++;
		std::cout << "Number of channels: " << nChannels << std::endl;

    }
	return (0);
}
