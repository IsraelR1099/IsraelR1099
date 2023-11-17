/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:49:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/17 13:34:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

std::map<std::string, Server::ft_reply>	Server::_replies
	= std::map<std::string, Server::ft_reply>();

Server::Server(void) : _m_g_run_server(false), _m_port(6667), m_password("default"), _m_fd_server(0)
{
}

Server::Server(char **argv)
{
	_m_port = atoi(argv[1]);
	if (_m_port < 1024 || _m_port > 65535)
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
	_m_g_run_server = true;
	_numChannels = 0;
}

Server::~Server(void)
{
}

void	Server::setServer(void)
{
	int	    rc;
	int	    val;

	rc = 0;
	_m_fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if (_m_fd_server < 0)
		throw Server::BadFormat("Socket() failed");
	else
    {
		std::cout << ANSI::bold << ANSI::green <<
            "Server succesfully created..." << ANSI::reset << std::endl;
        std::cout << "                           _______" << std::endl;
        std::cout << "                          | ___  o|" << std::endl;
        std::cout << "                          |[_-_]_ |" << std::endl;
        std::cout << "       ______________     |[_____]|" << std::endl;
        std::cout << "      |.------------.|    |[_____]|" << std::endl;
        std::cout << "      ||            ||    |[====o]|" << std::endl;
        std::cout << "      ||            ||    |[_.--_]|" << std::endl;
        std::cout << "      ||            ||    |[_____]|" << std::endl;
        std::cout << "      ||            ||    |      :|" << std::endl;
        std::cout << "      ||____________||    |      :|" << std::endl;
        std::cout << "  .==.|\"\"  ......    |.==.|      :|" << std::endl;
        std::cout << "  |::| '-.________.-' |::||      :|" << std::endl;
        std::cout << "  |''|  (__________)-.|''||______:|" << std::endl;
        std::cout << "`\"\"`_.............._\"\"`______" << std::endl;
        std::cout << "   /:::::::::::'':::\\`;'-.-.  \\" << std::endl;
        std::cout << "  /::=========.:.-::\"\\ \\ \\--\\   \\" << std::endl;
        std::cout << "  `\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"/  \\ \\__)   \\" << std::endl;
        std::cout << "\"\"\"\"\"\"\"\"\"\"`    '========'" << std::endl;
    }
	val = 1;
	rc = setsockopt(_m_fd_server, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	if (rc < 0)
		throw Server::BadFormat("setsockopt() failed");

	memset(&_server, 0, sizeof(_server));
	_server.sin_family = AF_INET;
	_server.sin_port = htons(_m_port);
	_server.sin_addr.s_addr = htonl(INADDR_ANY);
	rc = bind(_m_fd_server, (struct sockaddr *)&_server, sizeof(_server));
	if (rc < 0)
		throw Server::BadFormat("bind() failed");
	rc = listen(_m_fd_server, 5);
	if (rc < 0)
		throw Server::BadFormat("listen() failed");
	else
		std::cout << ANSI::bold << ANSI::green <<
            "Server listening..." << ANSI::reset <<
            std::endl;
	memset(m_fds, 0, sizeof(m_fds));
	m_fds[0].fd = _m_fd_server;
	m_fds[0].events = POLLIN;
    this->_initReplies();
}

int Server::launchServer(void)
{
    int rc;
    int nfds;

    nfds = 1;
    while (_m_g_run_server)
    {
        rc = poll(m_fds, nfds, -1);
		if (rc < 0)
            throw Server::ServerError("poll() failed");
        else if (rc == 0)
            throw Server::ServerError("poll() timed out");
        for (int i = 0; i < nfds; i++)
        {
            if (m_fds[i].revents == 0)
                continue;
            if (m_fds[i].revents != POLLIN)
            {
				if (m_fds[i].revents & POLLHUP)
				{
					std::cerr << ANSI::red <<
						"Error revents = " << m_fds[i].revents << " ctrl + d" << ANSI::reset <<
						std::endl;
					std::cerr << ANSI::red <<
						"client is: " << _clients[i].getNick() << ANSI::reset << std::endl;
					_removeClient(i, &nfds);
				}
				else if (m_fds[i].revents & POLLERR)
				{
					std::cerr << ANSI::red <<
						"Error revents = " << m_fds[i].revents << "POLLERR" << ANSI::reset <<
						std::endl;
				}
				else
				{
					std::cerr << ANSI::red <<
						"Error! revents = " << m_fds[i].revents << ANSI::reset <<
						std::endl;
				}
               // _m_g_run_server = false;
               // break;
            }
            if (m_fds[i].fd == m_fds[0].fd)
            {
				if (_acceptClient(nfds) < 0)
                {
                    perror("accept() failed");
					_m_g_run_server = false;
					throw Server::ServerError("accept() failed");
                }
				nfds++;
			}
			else
			{
				_receiveClient(i);
			}
        }
		std::map<int, Client>::iterator	it = _clients.begin();
		while (it != _clients.end())
		{
			Client	&client = it->second;
            std::cout << ANSI::blue <<
                "Client: " << client.getNick() << " connected..." <<
                ANSI::reset << std::endl;
			client.send_message();
            it++;
        }
        std::cout << ANSI::blue <<
            "Server is running..." << ANSI::reset <<
            std::endl;
        std::cout << "Number of channels: " <<
            _channels.size() << std::endl;
        std::cout << "Number of clients: " <<
            _clients.size() << std::endl;
    }
	return (0);
}
