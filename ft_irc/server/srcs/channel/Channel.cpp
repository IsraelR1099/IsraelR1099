/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:06:51 by israel            #+#    #+#             */
/*   Updated: 2023/10/29 20:32:53 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Channel.hpp"

Channel::Channel(void) : _topic("general")
{
}

Channel::Channel(std::string topic) : _topic(topic)
{
}

Channel::Channel(const Channel & src)
{
    *this = src;
}

Channel::~Channel(void)
{
}

std::string Channel::getTopic(void) const
{
    return this->_topic;
}

void Channel::setTopic(std::string &topic)
{
    this->_topic = topic;
}

size_t Channel::getNumClients(void) const
{
    return this->_clients.size();
}

void Channel::addClient(Client *client)
{
    this->_clients.insert(client);
}
