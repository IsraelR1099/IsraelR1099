/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:06:51 by israel            #+#    #+#             */
/*   Updated: 2023/12/01 09:36:08 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Channel.hpp"

Channel::Channel(void) : _name("general"), _password(""), _topic("general"), _numClients(0), _limit(5)
{
    this->_modeI = false;
    this->_modeT = false;
    this->_modeK = false;
    this->_modeO = false;
    this->_modeL = false;
}

Channel::Channel(const std::string &name) : _name(name), _password(""), _numClients(0), _limit(5), _key(""), _modeI(false), _modeT(false), _modeK(false), _modeO(false), _modeL(false)
{
	// std::cout << ANSI::green << "Channel: " << _name << " created and n of clients: " <<
	// 	getNumClients() << ANSI::reset << std::endl;
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

std::string	Channel::getTopicChanger(void)
{
    return (this->_topicChanger);
}

void	Channel::setTopicChanger(std::string topicChanger)
{
    this->_topicChanger = topicChanger;
}

time_t	Channel::getTopicChangeTime(void)
{
    return (this->_topicChangeTime);
}

void	Channel::setTopicChangeTime(time_t topicChangeTime)
{
    this->_topicChangeTime = topicChangeTime;
}

size_t	Channel::getNumClients(void) const
{
    return (this->_members.size());
}


void	Channel::incrementNumClients(void)
{
	this->_numClients = this->_numClients + 1;
}

std::map<int, Client>	&Channel::getMembers(void)
{
    return (this->_members);
}

std::map<int, Client>	&Channel::getOperators(void)
{
    return (this->_operators);
}

std::map<int, Client>	&Channel::getInvitees(void)
{
    return (this->_invitees);
}


size_t	Channel::getLimit(void)
{
	return (this->_limit);
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

bool    Channel::isClientInvited(const Client &client) const
{
    std::map<int, Client>::const_iterator it;

    for (it = _invitees.begin(); it != _invitees.end(); it++)
    {
        if (it->second.getNick() == client.getNick())
            return (true);
    }
    return (false);
}


void	Channel::addClient(const Client &member, int nfds, bool isOperator)
{
    std::map<int, Client>::iterator it;
	std::map<int, std::string>		params;

	params[0] = member.getNick() + "!" + member.getUser() + "@" +
		member.getHost() + " JOIN " + ":" + this->getName() + "\n";
    if (isOperator)
    {
		if (this->_key.length() == 0 && getNumClients() <= this->_limit)
		{
			_operators.insert(std::make_pair(nfds, member));
			_members.insert(std::make_pair(nfds, member));
		}
    }
    else
    {
        _members.insert(std::make_pair(nfds, member));
    }
    // for (it = _members.begin(); it != _members.end(); it++)
    // {
    //     Client &client = it->second;
    //     int rc = send(client.getSocketNumber(), params[0].c_str(), params[0].length(), 0);
    //     if (rc == -1)
    //         std::cout << "Error sending message to client: " << client.getNick() << std::endl;
    // }
}

bool    Channel::isClientInChannel(unsigned short clientIndex)
{
    if (_members.find(clientIndex) != _members.end())
        return (true);
    return false;
}

bool    Channel::isClientInChannel(const Client &client) const
{
    std::map<int, Client>::const_iterator itMember;
    std::map<int, Client>::const_iterator itOperator;

    itMember = _members.begin();

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
