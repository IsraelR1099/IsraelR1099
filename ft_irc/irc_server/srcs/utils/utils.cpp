/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:11:18 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/17 12:43:41 by irifarac         ###   ########.fr       */
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

void	Server::_removeClient(int socket, int *nfds)
{
	std::map<int, Client>::iterator	it;

	it = _clients.find(socket);
	if (it != _clients.end())
	{
		std::cout << "client is: " << it->second.getNick() << std::endl;
		_clients.erase(it);
	}
	*nfds = *nfds - 1;
}

