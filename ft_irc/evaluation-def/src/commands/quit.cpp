/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:53:02 by israel            #+#    #+#             */
/*   Updated: 2023/11/30 22:19:19 by davidbekic       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void Server::_quitCommand(std::string params, unsigned short clientIndex)
{
	std::map<int, Client>::iterator     itClients;
    std::map<int, Client>::iterator     itMembers;
    std::map<int, Channel>::iterator    itChannels;
	std::string						    message;

    message = ":" + this->_clients[clientIndex].getNick() +
        " QUIT " + params;
    itChannels = this->_channels.begin();
    for (; itChannels != this->_channels.end(); itChannels++)
    {
        if (itChannels->second.isClientInChannel(clientIndex))
        {
	        itClients = this->_clients.begin();
            for (; itClients != this->_clients.end(); itClients++)
            {
                itMembers = itChannels->second.getMembers().begin();
                for (; itMembers != itChannels->second.getMembers().end(); itMembers++)
                {
                    if (itMembers->first == itClients->first)
                    {
                        itClients->second.write_buffer(itClients->second, message);
                    }
                }
            }

        }
    }
	this->_removeClient(clientIndex);
}
