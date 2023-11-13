/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:06:51 by israel            #+#    #+#             */
/*   Updated: 2023/11/13 12:36:58 by irifarac         ###   ########.fr       */
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

std::map<int, Client>	&Channel::getMembers(void)
{
    return (this->_members);
}

void	Channel::addClient(const Client &member, int nfds, bool isOperator)
{
    std::map<int, Client>::iterator it;
	std::map<int, std::string>		params;

	params[0] = member.getNick() + "!" + member.getUser() + "@" +
		member.getHost() + " JOIN " + ":" + this->getName() + "\n";
	std::cout << "host de member: " << member.getHost() << std::endl;
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
    for (it = _members.begin(); it != _members.end(); it++)
    {
        Client &client = it->second;
        int rc = send(client.getSocketNumber(), params[0].c_str(), params[0].length(), 0);
        if (rc == -1)
            std::cout << "Error sending message to client: " << client.getNick() << std::endl;
    }
}

bool    Channel::isClientInChannel(const Client &client) const
{
    std::map<int, Client>::const_iterator itMember;
    std::map<int, Client>::const_iterator itOperator;

    for (itMember = _members.begin(); itMember != _members.end(); itMember++)
    {
        if (itMember->second.getNick() == client.getNick())
            return (true);
    }
    for (itOperator = _operators.begin(); itOperator != _operators.end(); itOperator++)
    {
        if (itOperator->second.getNick() == client.getNick())
            return (true);
    }
    return (false);
}
