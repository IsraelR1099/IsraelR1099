/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:02:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/27 09:48:21 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"
#include "../include/Client.hpp"


void Server::_parseCommand(std::string userInput, Client &client)
{
    std::string command;
    std::string params;
    std::string::size_type pos;

    pos = userInput.find(" ");
    if (pos != std::string::npos)
    {
        command = userInput.substr(0, pos);
        params = userInput.substr(pos + 1);
		params.erase(params.length() - 1); // remove newline of params
    }
    else
        command = userInput;
    if (command == "PASS")
    {
        _passCommand(params, client);
    }
    else if (command == "NICK")
    {
        if (client.getIsAuthorised())
            client.setNick(params);
        else
		{
			int rc = send(client.getSocketNumber(), "You must be authorised to use this command\n", 44, 0);
			if (rc < 0)
    		    throw Server::ServerError("send() failed");
		}
    }
    else if (command == "USER")
    {
        if (client.getIsAuthorised())
            client.setName(params);
        else
		{
			int rc = send(client.getSocketNumber(), "You must be authorised to use this command\n", 44, 0);
			if (rc < 0)
    		    throw Server::ServerError("send() failed");
		}
    }
    else {
		int rc = send(client.getSocketNumber(), "unknown command\n", 17, 0);
    if (rc < 0)
        throw Server::ServerError("send() failed");
    }
}

int	Server::acceptClient(int nfds)
{
	int				new_fd;

	new_fd = accept(m_fds[0].fd, NULL, NULL);
	if (new_fd < 0)
		return (-1);
	m_fds[nfds].fd = new_fd;
	m_fds[nfds].events = POLLIN;
	Client newClient(new_fd);
    _clients.insert(std::make_pair(nfds, newClient));
	return (0);
}

void	Server::receiveClient(int i)
{
	int     rc;
	char	buffer[1024];

	memset(buffer, 0, sizeof(buffer));
	rc = recv(m_fds[i].fd, buffer, sizeof(buffer), 0);
	if (rc < 0)
		throw Server::ServerError("recv() failed");
	else if (rc == 0)
		throw Server::ServerError("Connection closed");
	_parseCommand(buffer, _clients[i]);
	std::cout << "Client: " << buffer << std::endl;
    // rc = send(_m_fds[i].fd, "Message received\n", 18, 0);
    if (rc < 0)
        throw Server::ServerError("send() failed");
}
