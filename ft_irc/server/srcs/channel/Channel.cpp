/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:06:51 by israel            #+#    #+#             */
/*   Updated: 2023/11/01 10:33:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Channel.hpp"

Channel::Channel(void) : _topic("general")
{
}

Channel::Channel(const std::string &topic) : _topic(topic)
{
	std::cout << ANSI::green << "Channel: " << _topic << " created and n of clients: " <<
		getNumClients() << ANSI::reset << std::endl;
}

Channel::Channel(const Channel &src)
{
    *this = src;
}

Channel::~Channel(void)
{
}

std::string Channel::getTopic(void) const
{
    return (this->_topic);
}

void Channel::setTopic(const std::string &topic)
{
    this->_topic = topic;
}

size_t Channel::getNumClients(void) const
{
    return (this->_members.size());
}

void Channel::addClientTo(int nfds, std::string &chan, Client member)
{
	_members.insert(std::make_pair(nfds, member));
	std::cout << "Client: " << member.getNick() << " added to: " <<
		getTopic() << std::endl;
	(void)chan;
}
