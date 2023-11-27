/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:06:51 by israel            #+#    #+#             */
/*   Updated: 2023/11/27 12:27:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Channel.hpp"

Channel::Channel(void) : _name("general"), _key(""), _topic("general"), _numClients(0), _limit(5)
{
    this->_modeI = false;
    this->_modeT = false;
    this->_modeK = false;
    this->_modeL = false;
}

Channel::Channel(const std::string &name) : _name(name), _key(""), _numClients(0), _limit(5), _passwd(false), _modeI(false), _modeT(false), _modeK(false), _modeL(false)
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

std::map<int, Client>   &Channel::getMembers(void)
{
    return (this->_members);
}

std::map<int, Client>   &Channel::getOperators(void)
{
    return (this->_operators);
}

std::map<int, Client>	&Channel::getInvitees(void)
{
    return (this->_invitees);
}

void    Channel::setLimit(size_t limit)
{
    _limit = limit;
}

bool    Channel::getModeT()
{
    return _modeT;
}

void    Channel::setModeT(bool boolean)
{
    _modeT = boolean;
}

bool    Channel::getModeI()
{
    return _modeI;
}

void    Channel::setModeI(bool boolean)
{
    _modeI = boolean;
}

bool    Channel::getModeL()
{
    return _modeL;
}

void    Channel::setModeL(bool boolean)
{
    _modeL = boolean;
}

std::string    Channel::getKey()
{
    return _key;
}

void    Channel::setKey(std::string key)
{
    _key = key;
}

void	Channel::addClient(const Client &member, int nfds, bool isOperator)
{
    std::map<int, Client>::iterator it;
	std::map<int, std::string>		params;
    std::vector<std::string>        nameReply;

    std::cout << "Channel: " << this->getName() << " adding client: " << member.getNick() << std::endl;
/*	params[0] = member.getNick() + "!" + member.getUser() + "@" +
		member.getHost() + " JOIN " + ":" + this->getName() + "\n";
    nameReply[0] = "#" + this->getName();
    nameReply[1] = "1";*/
    if (isOperator)
    {
		if (this->_passwd == false && getNumClients() <= this->_limit)
		{
			std::cout << "Client: " << member.getNick() << " added to: " <<
					this->getName() << " as operator" << std::endl;
			_operators.insert(std::make_pair(nfds, member));
			_members.insert(std::make_pair(nfds, member));
            std::map<int, Client>::iterator it = this->_members.begin();

            while (it != this->_members.end())
            {
                std::cout << "Client: " << it->second.getNick() << std::endl;
                std::cout << "client socket: " << it->second.getSocketNumber() << std::endl;
                it++;
            }
		}
    }
    else
    {
		if (this->_key == "" && getNumClients() <= _limit)
		{
			_members.insert(std::make_pair(nfds, member));
			std::cout << "Client: " << member.getNick() << " added to: " <<
			this->getName() << std::endl;
		}
    }
 /*   for (it = _members.begin(); it != _members.end(); it++)
    {
        Client &client = it->second;
        client.write_buffer(it->second, params[0]);
        int rc = send(client.getSocketNumber(), params[0].c_str(), params[0].length(), 0);
        if (rc == -1)
            std::cout << "Error sending message to client: " << client.getNick() << std::endl;
    }*/
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

void    Channel::removeChannelClient(const Client &client)
{
    std::map<int, Client>::iterator itMember;
    std::map<int, Client>::iterator itOperator;

    for (itMember = _members.begin(); itMember != _members.end(); itMember++)
    {
        if (itMember->second.getNick() == client.getNick())
        {
            _members.erase(itMember);
            break ;
        }
    }
    for (itOperator = _operators.begin(); itOperator != _operators.end(); itOperator++)
    {
        if (itOperator->second.getNick() == client.getNick())
        {
            _operators.erase(itOperator);
            break ;
        }
    }
}
