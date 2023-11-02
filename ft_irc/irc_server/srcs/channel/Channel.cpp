/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:06:51 by israel            #+#    #+#             */
/*   Updated: 2023/11/02 17:11:08 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Channel.hpp"

Channel::Channel(void) : _name("general"), _topic("general")
{
}

Channel::Channel(const std::string &name) : _name(name)
{
	std::cout << ANSI::green << "Channel: " << _name << " created and n of clients: " <<
		getNumClients() << ANSI::reset << std::endl;
}

Channel::Channel(const Channel &src)
{
    *this = src;
}

Channel::~Channel(void)
{
}

std::string Channel::getName(void) const
{
    return (this->_name);
}

void Channel::setName(const std::string &name)
{
    this->_name = name;
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

void Channel::addClient(const Client &member, int nfds, bool isOperator)
{
    if (isOperator)
    {
        std::cout << "Client: " << member.getNick() << " added to: " <<
                this->getName() << " as operator" << std::endl;
        _operators.insert(std::make_pair(nfds, member));
    }
    else
    {
        _members.insert(std::make_pair(nfds, member));
	std::cout << "Client: " << member.getNick() << " added to: " <<
		this->getName() << std::endl;
    }
}
