/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:53:02 by israel            #+#    #+#             */
/*   Updated: 2023/11/30 13:48:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void Server::_quitCommand(std::string params, unsigned short clientIndex)
{
	std::map<int, Client>::iterator	itClients;
	std::string						message;

	message = "ERROR :Closing link: (" +
		this->_clients[clientIndex].getNick() +
		"@" + this->_clients[clientIndex].getHost() +
		") [Quit: " + params + "]";
	itClients = this->_clients.begin();
	for (; itClients != this->_clients.end(); itClients++)
	{
		itClients->second.write_buffer(itClients->second, message);
	}
	this->_removeClient(clientIndex);
}
