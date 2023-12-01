/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:02:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/12/01 09:54:24 by irifarac         ###   ########.fr       */
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
        pos = line.find(" ");
        if (pos != std::string::npos)
        {
            command = line.substr(0, pos);
            params = line.substr(pos + 1);
            params = removeTrailingWhitespace(params);
        }
        else
            command = line;
        this->_cmd_name = command;
        this->_cmd_params = params;
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
            _joinCommand(params, clientIndex);
        }
        else if (command == "MODE")
        {
            _modeCommand(params, clientIndex);
        }
        else if (command == "PING")
            _pingCommand(params, clientIndex);
        else if (command == "TOPIC")
            _topicCommand(params, clientIndex);
        else if (command == "INVITE")
        {
            _inviteCommand(params, clientIndex);
        }
        else if (command == "KICK")
        {
            _kickCommand(params, clientIndex);
        }
        else if (command == "PART")
        {
            _partCommand(params, clientIndex);
        }
        else if (command == "QUIT")
        {
            _quitCommand(params, clientIndex);
        }
        else
        {
            std::string message;
            if (_clients[clientIndex].getNick().empty())
                message = "*";
            else
                message = _clients[clientIndex].getNick();
            message += " " + command + " :Unknown command";
            Server::_message(Reply::ERR_UNKNOWNCOMMAND, _clients[clientIndex], std::vector<std::string>(1, message));
            break ;
        }
		std::cout << ANSI::reset << ANSI::bold <<
            "[ CMD ]:\t" << ANSI::reset <<
            ANSI::cmd << this->_cmd_name << ANSI::reset <<
            ' ' <<
            ANSI::arg << this->_cmd_params << ANSI::reset << std::endl;
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

int	Server::_acceptClient(void)
{
	int				    new_fd;
    struct sockaddr_in  client_addr;
    struct pollfd       client_fd;
    socklen_t           client_len;
    std::ostringstream  oss;

    client_len = sizeof(client_addr);
    new_fd = accept(this->_poll_fds[0].fd, (struct sockaddr *)&client_addr, &client_len);
	if (new_fd < 0)
		return (-1);
	else
    {
        std::cout << ANSI::bold << "\tnew client accepted:\t| " <<
            new_fd << "\t| " << inet_ntoa(client_addr.sin_addr) <<
            "\t| " << ntohs(client_addr.sin_port) << ANSI::reset << std::endl;
    }
    oss << inet_ntoa(client_addr.sin_addr);
    client_fd.fd = new_fd;
    client_fd.events = POLLIN;
    this->_poll_fds.push_back(client_fd);
	Client newClient(new_fd);
    _clients.insert(std::make_pair(new_fd, newClient));
	_clients[new_fd].setHost(oss.str());
   	return (0);
}


int Server::_receiveClient(int i)
{
	int								rc;
	int								client;
	char							buffer[1024];
    std::string						receivedData;
    size_t							delimiterPos;
	std::map<int, Client>::iterator	itClient = this->_clients.find(i);
	std::vector<struct pollfd>::iterator	itFd = this->_poll_fds.begin();

    if (itClient == this->_clients.end())
    {
        return (-1);
    }
	std::memset(buffer, 0, sizeof(buffer));
	client = 0;
	while (itFd != this->_poll_fds.end())
	{
		if (itFd->fd == i)
			break ;
		itFd++;
		client++;
	}
    if (client >= (int)this->_poll_fds.size())
    {
        return (-1);
    }
    rc = recv(this->_poll_fds[client].fd, buffer, sizeof(buffer), 0);
	if (rc < 0)
    {
		throw Server::ServerError("recv() failed");
    }
	else if (rc == 0)
    {
        _removeClient(i);
        return (-1);
    }
	if (itClient != this->_clients.end())
	{
		if (!itClient->second.getLineCommand().empty())
		{
			itClient->second.setLineCommand(itClient->second.getLineCommand() + buffer);
		}
		else
			itClient->second.setLineCommand(buffer);
	}
	else
		return (-1);
	delimiterPos = itClient->second.getLineCommand().find("\r\n");
	while (delimiterPos != std::string::npos)
	{
		receivedData = itClient->second.getLineCommand();
		this->_parseCommand(receivedData.substr(0, delimiterPos), i);
		itClient->second.setLineCommand(receivedData.substr(delimiterPos + 2));
		delimiterPos = itClient->second.getLineCommand().find("\r\n");
	}
	if (!itClient->second.getLineCommand().empty())
	{
		if (itClient != this->_clients.end())
			this->_clients[i].writeIncomplBuffer(itClient->second, receivedData);
	}
    return (0);
}


void    Server::_reply(unsigned short clientIndex, const std::string &message)
{
    std::string messageWithNewLine = message + "\r\n";

    int rc = send(_clients[clientIndex].getSocketNumber(), messageWithNewLine.c_str(), messageWithNewLine.length(), 0);
    if (rc < 0)
        throw Server::ServerError("send() failed");
}

std::vector<std::string> Server::_splitString(const std::string &s, char delim)
{
    std::vector<std::string>    result;
    std::stringstream           ss(s);
    std::string                 item;

    while (std::getline(ss, item, delim))
        result.push_back(item);
    return (result);
}

Channel	*Server::_getChannelByName(const std::string channelName)
{
	std::map<int, Channel>::iterator	it;

	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		Channel	&channel = it->second;
		if (channel.getName() == channelName)
			return (&channel);
	}
	return (0);
}

void	Server::_incrementChannels(void)
{
	this->_numChannels = this->_numChannels + 1;
}

void	Server::_removeClient(int socket)
{
	std::map<int, Client>::iterator         it;
    std::vector<struct pollfd>::iterator    itPoll;
    std::map<int, Channel>::iterator        itChannel;

	it = this->_clients.find(socket);
    if (it != this->_clients.end())
	{
        itPoll = std::remove_if(this->_poll_fds.begin(),
                this->_poll_fds.end(), PollFDCompare(it->second.getSocketNumber()));
        close(it->second.getSocketNumber());
        this->_poll_fds.erase(itPoll, this->_poll_fds.end());
        itChannel = this->_channels.begin();
        while (itChannel != this->_channels.end())
        {
            itChannel->second.removeChannelClient(it->second);
            itChannel++;
        }
		this->_clients.erase(it);
        if (this->_clients.empty())
            this->_clients.clear();
	}
}

int    Server::_checkRegisteredAndParams(const std::string &params, unsigned short clientIndex)
{
    if (!_clients[clientIndex].getIsRegistered())
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_NOTREGISTERED, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return 1;
    }
    if (!params.length())
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return 1; 
    }
    return 0;
}
