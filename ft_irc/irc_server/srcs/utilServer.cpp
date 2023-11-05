/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:02:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/05 20:47:50 by israel           ###   ########.fr       */
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

    std::istringstream  iss(userInput);
    std::string         line;
    while (std::getline(iss, line, '\n'))
    {
        command.erase(command.find_last_not_of(" \n\r\t") + 1);
        std::cout << "line: |" << ANSI::red << line << ANSI::reset << "|" << std::endl;
        pos = line.find(" ");
        if (pos != std::string::npos)
        {
            command = line.substr(0, pos);
            params = line.substr(pos + 1);
            params = removeTrailingWhitespace(params);
        }
        else
            command = line;
        std::cout << "command: |" << ANSI::red << command << ANSI::reset << "|" << std::endl;
        if (command == "CAP")
        {
            _capCommand(params, clientIndex);
        }
        else if (command == "PASS")
        {
            std::cout << "entro en pass" << std::endl;
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
        else if (command == "MODE")
        {
            _modeCommand(params, clientIndex);
        }
        else if (command == "PING")
            _pingCommand(params, clientIndex);
        else
        {
            std::cout << "unknown command is: |" << command << "|" << std::endl;
            _sendMessageToClient("unknown command\r\n", clientIndex);
            break ;
        }
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

void    Server::_reply(unsigned short clientIndex, const std::string &message)
{
    std::string messageWithNewLine = message + "\r\n";

    int rc = send(_clients[clientIndex].getSocketNumber(), messageWithNewLine.c_str(), messageWithNewLine.length(), 0);
    if (rc < 0)
        throw Server::ServerError("send() failed");
}
