/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:09:57 by israel            #+#    #+#             */
/*   Updated: 2023/11/28 14:45:07 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

bool    Server::addClientToChannel(Channel &channel, Client &client, unsigned short clientIndex, std::string password)
{
    Channel *tmp = _getChannelByName(channel.getName());

    std::cout << "password: |" << password << "|" << std::endl;
    std::cout << "tmp->getKey(): |" << tmp->getKey() << "|" << std::endl;
    if (tmp->getKey() == password)
        std::cout << "son iguales" << std::endl;
    else
        std::cout << "son diferentes" << std::endl;
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
        return false;
    }
    else
    {
        channel.addClient(client, clientIndex, false);
        return true;
    }
}

//Check limits, if it's invited and password
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
    std::cout << "tenemos " << tokens.size() << " tokens" << std::endl;
    if (tokens.size() > 1)
        password = tokens[1];
    if (itClient != _clients.end())
    {
        Client  &client = itClient->second;
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
        }
        itMembers = this->_clients.begin();
        std::string memberList;
        std::string operatorFlag;
        while (itMembers != this->_clients.end())
        {
            if (itMembers->second.getIsRegistered() == true)
            {
                std::string message;
                std::string message2;
                operatorFlag = itMembers->second.getIsOperator() ? "@" : "";
                message = client.getNick() + "!" + client.getUser()
                    + "@" + client.getHost() + " JOIN ";
                message2 = tokens[0];
                if (memberList.empty())
                    memberList = operatorFlag + itMembers->second.getNick();
                else
                    memberList += " " + operatorFlag + itMembers->second.getNick();
                std::vector<std::string>    params;
                params.push_back(message);
                params.push_back(message2);
                Server::_message(Reply::RPL_TOPIC, itMembers->second, params);

            }
            itMembers++;
        }
        std::string                 message3;
        std::vector<std::string>    params2;
        message3 = tokens[0];
        params2.push_back(message3);
        params2.push_back(memberList);
        itMembers = this->_clients.begin();
        for (; itMembers != this->_clients.end(); itMembers++)
        {
            Server::_message(Reply::RPL_NAMREPLY, itMembers->second, params2);
            Server::_message(Reply::RPL_ENDOFNAMES, itMembers->second,
                    std::vector<std::string>(1, message3));
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
                std::cout << "prefix: " << prefix << std::endl;
                Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
            }
            else
            {
                std::cout << ANSI::green << "JOIN: " << channelName <<
                ANSI::reset << std::endl;
                _joinChannel(channelName, clientIndex);
            }
            it++;
        }
    }
}
