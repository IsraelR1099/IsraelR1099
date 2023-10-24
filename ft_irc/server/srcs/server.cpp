/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:49:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/24 20:57:17 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

Server::Server(void) : m_g_run_server(false), m_port(6667), m_password("default"), m_fd(0)
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
	int	rc;
	int	val;

	rc = 0;
	m_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_fd < 0)
		throw Server::BadFormat("Socket() failed");
	else
		std::cout << "Socket succesfully created..." <<std::endl;
	val = 1;
	rc = setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	if (rc < 0)
		throw Server::BadFormat("setsockopt() failed");
	else
		std::cout << "setsockopt succesfully set..." << std::endl;

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(m_port);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	rc = bind(m_fd, (struct sockaddr *)&server, sizeof(server));
	if (rc < 0)
		throw Server::BadFormat("bind() failed");
	else
		std::cout << "Socket succesfully binded" << std::endl;
	rc = listen(m_fd, 5);
	if (rc < 0)
		throw Server::BadFormat("listen() failed");
	else
		std::cout << "Server listening..." << std::endl;
	memset(fds, 0, sizeof(fds));
	fds[0].fd = m_fd;
	fds[0].events = POLLIN;
}

int Server::launchServer(void)
{
    int rc;
    int nfds;
    std::vector<pollfd> fds;
    std::vector<pollfd>::iterator it;

    fds.push_back(fds[0]);
    nfds = 1;
    while (m_g_run_server)
    {
        rc = poll(fds, nfds, 10000);
        if (rc < 0)
            throw Server::ServerError("poll() failed");
        else if (rc == 0)
            throw Server::ServerError("poll() timed out");
        else
            std::cout << "poll() succesfully set..." << std::endl;
        for (int i = 0; i < nfds; i++)
        {
            if (it->revents == 0)
                continue;
            if (it->revents != POLLIN)
            {
                std::cout << "Error! revents = " << it->revents << std::endl;
                m_g_run_server = false;
                break;
            }
            if (it->fd == fds[0].fd)
            {
                std::cout << "Listening socket is readable" << std::endl;

            }

        }

    }
}
