/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:02:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/02 21:33:11 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"
#include "../include/Client.hpp"
#include "../include/Channel.hpp"

std::string removeTrailingWhitespace(const std::string &str)
{
    std::string result = str;

    int end = result.length() - 1;
    while (end >= 0 && std::isspace(result[end]))
        --end;
    if (end < static_cast<int>(result.length()) - 1)
        result = result.substr(0, end + 1);
    return (result);
}

void Server::_parseCommand(std::string userInput, unsigned short clientIndex)
{
    std::string             command;
    std::string             params;
    std::string::size_type  pos;

    pos = userInput.find(" ");
    if (pos != std::string::npos)
    {
        command = userInput.substr(0, pos);
        params = userInput.substr(pos + 1);
        params = removeTrailingWhitespace(params);
    }
    else
        command = userInput;
    if (command == "CAP")
    {
        _capCommand(params, clientIndex);
    }
    else if (command == "PASS")
    {
        _passCommand(params, clientIndex);
    }
    else if (command == "NICK")
    {
        _nickCommand(params, clientIndex);
    }
    else if (command == "USER")
    {
        _userCommand(params, clientIndex);
    }
    else if (command == "PRIVMSG")
    {
        _privmsgCommand(params, clientIndex);
    }
    else if (command == "JOIN")
    {
        std::cout << "entro en join" << std::endl;
        _joinCommand(params, clientIndex);
    }
    else
    {
        _sendMessageToClient("unknown command", clientIndex);
    }
}
std::vector<std::string>    Server::_getAllClientNicknames(std::map<int, Client>&clients)
{
    std::vector<std::string>        nicknames;
    std::map<int, Client>::iterator it;

    for (it = clients.begin(); it != clients.end(); it++)
    {
        nicknames.push_back(it->second.getNick());
    }
    return (nicknames);
}

/*void    Server::_joinChannel(int nfds, std::string chan, Client &member)
{
    std::map<int, Channel>::iterator it;

    for (it = _channels.begin(); it != _channels.end(); it++)
    {
        Channel   &channel = it->second;
        if (channel.getTopic() == chan)
        {
            channel.addClientTo(nfds, chan, member);
            break ;
        }
    }
}
*/
int	Server::_acceptClient(int nfds)
{
	int				    new_fd;
    struct sockaddr_in  client_addr;
    socklen_t           client_len;

    client_len = sizeof(client_addr);
	new_fd = accept(m_fds[0].fd, (struct sockaddr *)&client_addr, &client_len);
	if (new_fd < 0)
		return (-1);
    else
    {
        std::cout << ANSI::bold << "\tnew client accepted:\t| " <<
            new_fd << "\t| " << inet_ntoa(client_addr.sin_addr) <<
            "\t| " << ntohs(client_addr.sin_port) << ANSI::reset << std::endl;
    }
   	m_fds[nfds].fd = new_fd;
	m_fds[nfds].events = POLLIN;
	Client newClient(new_fd);
    _clients.insert(std::make_pair(nfds, newClient));
	return (0);
}

void	Server::_receiveClient(int i)
{
	int     rc;
	char	buffer[1024];

	memset(buffer, 0, sizeof(buffer));
	rc = recv(m_fds[i].fd, buffer, sizeof(buffer), 0);
	if (rc < 0)
		throw Server::ServerError("recv() failed");
	else if (rc == 0)
		throw Server::ServerError("Connection closed");
    std::cout << "Server: |" << buffer << "|" << std::endl;
	_parseCommand(buffer, i);
    if (rc < 0)
        throw Server::ServerError("send() failed");
}
