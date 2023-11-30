/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:09:57 by israel            #+#    #+#             */
/*   Updated: 2023/11/30 21:55:42 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void	Server::printWelcome(Channel &channel, Client &client)
{
    std::map<int, Client>	        members;
	std::map<int, Client>::iterator	itMembers;
	std::string						channelName;
	std::string						operatorFlag;
	std::string						user;
	std::string						memberList;
    std::vector<std::string>        nameReply;
    std::vector<std::string>        topicReply;

    members = channel.getMembers();
	itMembers = members.begin();
    channelName = channel.getName();
    memberList = "";
    for (std::map<int, Client>::iterator itClients = _clients.begin(); itClients != _clients.end(); itClients++)
    {
        for (itMembers = members.begin(); itMembers != members.end(); itMembers++)
        {
            if (itMembers->second.getNick() == itClients->second.getNick())
            {
                if (itMembers->second.getIsOperator())
                    operatorFlag = "@";
                else
                    operatorFlag = "";
                user = client.getNick() + "!" + client.getUser()
                    + "@" + client.getHost() + " JOIN ";
                if (memberList.empty())
                    memberList = operatorFlag + itMembers->second.getNick();
                else
                    memberList += " " + operatorFlag + itMembers->second.getNick();
                topicReply.push_back(user);
                topicReply.push_back(channelName);
                Server::_message(Reply::RPL_TOPIC, itClients->second, topicReply);
            }
        }
    }
    nameReply.push_back(channelName);
    nameReply.push_back(memberList);
    itMembers = members.begin();
    for (std::map<int, Client>::iterator itClients = _clients.begin(); itClients != _clients.end(); itClients++)
    {
        for (itMembers = members.begin(); itMembers != members.end(); itMembers++)
        {
            if (itMembers->second.getNick() == itClients->second.getNick())
            {
                Server::_message(Reply::RPL_NAMREPLY, itClients->second, nameReply);
                Server::_message(Reply::RPL_ENDOFNAMES, itClients->second,
                        std::vector<std::string>(1, channelName));
            }
        }
    }
}

bool    Server::addClientToChannel(Channel &channel, Client &client, unsigned short clientIndex, std::string password)
{
    Channel					*tmp = _getChannelByName(channel.getName());
	std::map<int, Client>	members;

    if (tmp->isClientInChannel(client))
    {
        return false;
    }
    else if (tmp->getNumClients() >= tmp->getLimit())
    {
        std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);
        if (itClient != _clients.end())
        {
            std::string	prefix = itClient->second.getCustomPrefix("471", channel.getName());
            Server::_message(Reply::ERR_CHANNELISFULL, itClient->second, std::vector<std::string>(1, prefix));
        }
        return false;
    }
    else if (tmp->getKey() != password)
    {
        std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);
        if (itClient != _clients.end())
        {
            std::string	prefix = itClient->second.getCustomPrefix("475", channel.getName());
            Server::_message(Reply::ERR_BADCHANNELKEY, itClient->second, std::vector<std::string>(1, prefix));
        }
        return false;
    }
    else if (tmp->getModeI() && !tmp->isClientInvited(client))
    {
        std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);
        if (itClient != _clients.end())
        {
            std::string	prefix = itClient->second.getCustomPrefix("473", channel.getName());
            Server::_message(Reply::ERR_INVITEONLYCHAN, itClient->second, std::vector<std::string>(1, prefix));
        }
        return (false);
    }
    else
    {
        channel.addClient(client, clientIndex, false);
        this->printWelcome(channel, client);
    }

        return (true);
}

void    Server::_joinChannel(std::string channelName, unsigned short clientIndex)
{
    bool                                channelExists = false;
    std::map<int, Channel>::iterator    it;
    std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);
    std::map<int, Client>::iterator     itMembers;
    std::vector<std::string>            tokens;
    std::istringstream                  iss(channelName);
    std::string                         token;
    std::string                         password;

    while (iss >> token)
        tokens.push_back(token);
    if (tokens.size() > 1)
        password = tokens[1];
    if (itClient != _clients.end())
    {
        Client &client = itClient->second;
        if (client.getIsRegistered() == false)
        {
            std::cout << ANSI::red <<
            "ERR_NOTREGISTERED :You have not registered" <<
            ANSI::reset << std::endl;
            std::string prefix = client.getCustomPrefix("451");
            Server::_message(Reply::ERR_NOTREGISTERED, client, std::vector<std::string>(1, prefix));
            return ;
        }
        for (it = _channels.begin(); it != _channels.end(); it++)
        {
            const Channel &channel = it->second;
            if (channel.getName() == tokens[0])
            {
                channelExists = true;
                break ;
            }
        }
        if (channelExists)
        {
            if (addClientToChannel(it->second, client, clientIndex, password) == false)
                return ;
        }
        else
        {
            Channel newChannel(tokens[0]);
            newChannel.addClient(client, clientIndex, true);
            this->_channels.insert(std::make_pair(this->_numChannels, newChannel));
			newChannel.incrementNumClients();
			this->_incrementChannels();
            client.setIsOperator(true);
            this->printWelcome(newChannel, client);
        }
    }
    else
    {
        std::cout << "Client not found" << std::endl;
        return ;
    }

}

void    Server::_joinCommand(std::string params, unsigned short clientIndex)
{
    std::vector<std::string>    paramsVector;
    std::istringstream          iss(params);
    std::string                 token;

    while (std::getline(iss, token, ','))
        paramsVector.push_back(token);
    if (paramsVector.size() < 1)
    {
        std::cout << ANSI::red <<
        "ERR_NEEDMOREPARAMS :Not enough parameters" <<
        ANSI::reset << std::endl;
        std::string prefix = _clients[clientIndex].getCustomPrefix("461", "JOIN");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }
    else
    {
        std::vector<std::string>::iterator it = paramsVector.begin();
        while (it != paramsVector.end())
        {
            const std::string   &channelName = *it;
            if (channelName[0] != '#')
            {
                std::cout << ANSI::red <<
                "ERR_NOSUCHCHANNEL :No such channel" <<
                ANSI::reset << std::endl;
                std::string prefix = _clients[clientIndex].getCustomPrefix("403", params);
                Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
            }
            else
            {
                _joinChannel(channelName, clientIndex);
            }
            it++;
        }
    }
}
