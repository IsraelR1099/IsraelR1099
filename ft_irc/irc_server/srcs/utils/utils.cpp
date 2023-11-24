/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:11:18 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/24 10:49:33 by irifarac         ###   ########.fr       */
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

int	Server::_getChannelKey(const std::string &channelName)
{
	std::map<int, Channel>::iterator	itChannel;

	for (itChannel = this->_channels.begin(); itChannel != this->_channels.end(); itChannel++)
	{
		Channel	&channel = itChannel->second;
		if (channel.getName() == channelName)
			return (itChannel->first);
	}
	return (-1);
}

void	Server::_incrementChannels(void)
{
	this->_numChannels = this->_numChannels + 1;
}

void	Server::_removeClient(int socket)
{
	std::map<int, Client>::iterator         it;
    std::vector<struct pollfd>::iterator    itPoll;

	it = _clients.find(socket);
    if (it != _clients.end())
	{
        itPoll = std::remove_if(this->_poll_fds.begin(),
                this->_poll_fds.end(), PollFDCompare(it->second.getSocketNumber()));
        close(it->second.getSocketNumber());
        this->_poll_fds.erase(itPoll, this->_poll_fds.end());
		_clients.erase(it);
        if (this->_clients.empty())
            this->_clients.clear();
	}
}

