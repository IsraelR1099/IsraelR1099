/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:11:18 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/30 13:40:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

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
