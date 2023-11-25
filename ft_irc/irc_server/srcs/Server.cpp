/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:49:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/23 21:08:35 by israel           ###   ########.fr       */
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
	int	            rc;
	int	            val;
    struct pollfd   server;

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
    std::memset(&server, 0, sizeof(server));
    server.fd = _m_fd_server;
    server.events = POLLIN;
    this->_poll_fds.push_back(server);
    this->_initReplies();
}

int Server::launchServer(void)
{
    int rc;
    int nfds;

    nfds = 1;
    while (_m_g_run_server)
    {
        rc = poll(&this->_poll_fds[0], this->_poll_fds.size(), -1);
		if (rc < 0)
            throw Server::ServerError("poll() failed");
        else if (rc == 0)
            throw Server::ServerError("poll() timed out");
        if (this->_poll_fds[0].revents == POLLIN)
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
            std::vector<struct pollfd>::iterator it = this->_poll_fds.begin();
            int i = 0;
            while (it != this->_poll_fds.end())
            {
                if (it->revents == POLLIN)
                {
                    if (this->_receiveClient(i) < 0)
                    {
                        it = this->_poll_fds.begin();
                        i = 0;
                        nfds--;
                    }
                }
				else if (it->revents & POLLHUP)
				{
					this->_removeClient(i);
					it = this->_poll_fds.begin();
					i = 0;
					nfds--;
					std::cout << ANSI::red << "ctrl detected POLLHUP" << ANSI::reset << std::endl;
				}
                it++;
                i++;
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
        std::vector<struct pollfd>::iterator it2 = this->_poll_fds.begin();
        while (it2 != _poll_fds.end())
        {
            std::cout << "fd: " << it2->fd << std::endl;
            it2++;
        }
        std::map<int, Client>::iterator it3 = _clients.begin();
        while (it3 != _clients.end())
        {
            std::cout << "key client: " << it3->first << std::endl;
            std::cout << "Client nick en loop: " << it3->second.getNick() << std::endl;
            it3++;
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
