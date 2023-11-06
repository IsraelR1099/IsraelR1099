/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:06:51 by israel            #+#    #+#             */
/*   Updated: 2023/11/06 12:03:49 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Channel.hpp"

Channel::Channel(void) : _name("general"), _password(""), _topic("general"), _numClients(0), _limit(5)
{
    this->_modeI = false;
    this->_modeT = false;
    this->_modeK = false;
    this->_modeO = false;
    this->_modeL = false;
}

Channel::Channel(const std::string &name) : _name(name), _password(""), _numClients(0), _limit(5), _passwd(false), _modeI(false), _modeT(false), _modeK(false), _modeO(false), _modeL(false)
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

std::string	Channel::getName(void) const
{
    return (this->_name);
}

void	Channel::setName(const std::string &name)
{
    this->_name = name;
}

std::string	Channel::getTopic(void) const
{
    return (this->_topic);
}

void	Channel::setTopic(const std::string &topic)
{
    this->_topic = topic;
}

size_t	Channel::getNumClients(void) const
{
    return (this->_members.size());
}

size_t	Channel::getLimit(void)
{
	return (this->_limit);
}

void	Channel::incrementNumClients(void)
{
	this->_numClients = this->_numClients + 1;
}

void	Channel::addClient(const Client &member, int nfds, bool isOperator)
{
    if (isOperator)
    {
		if (this->_passwd == false && getNumClients() <= this->_limit)
		{
			std::cout << "Client: " << member.getNick() << " added to: " <<
					this->getName() << " as operator" << std::endl;
			_operators.insert(std::make_pair(nfds, member));
			_members.insert(std::make_pair(nfds, member));
		}
    }
    else
    {
		if (this->_password == "" && getNumClients() <= _limit)
		{
			_members.insert(std::make_pair(nfds, member));
			std::cout << "Client: " << member.getNick() << " added to: " <<
			this->getName() << std::endl;
		}
    }
}
