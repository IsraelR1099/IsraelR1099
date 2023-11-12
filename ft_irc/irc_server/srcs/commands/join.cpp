/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:09:57 by israel            #+#    #+#             */
/*   Updated: 2023/11/11 20:40:38 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

bool    Server::addClientToChannel(Channel &channel, Client &client, unsigned short clientIndex)
{
    Channel *tmp = _getChannelByName(channel.getName());

    if (tmp->isClientInChannel(client))
    {
        return false;
    }
    else if (tmp->getNumClients() > tmp->getLimit())
    {
        std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);
        if (itClient != _clients.end())
        {
            std::string	prefix = itClient->second.getCustomPrefix("471", channel.getName());
            Server::_message(Reply::ERR_CHANNELISFULL, itClient->second, std::vector<std::string>(1, prefix));
        }
        return false;
    }
    else
    {
        std::cout << "name channel es: " << tmp->getName() << std::endl;
        channel.addClient(client, clientIndex, false);
        return true;
    }
}

void    Server::_joinChannel(std::string channelName, unsigned short clientIndex)
{
    bool                                channelExists = false;
    std::map<int, Channel>::iterator    it;
    std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);

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
            if (channel.getName() == channelName)
            {
                channelExists = true;
                break ;
            }
        }
        if (channelExists)
        {
            if (addClientToChannel(it->second, client, clientIndex) == false)
                return ;
        }
        else
        {
            Channel newChannel(channelName);
            _channels.insert(std::make_pair(0, newChannel));
            newChannel.addClient(client, clientIndex, true);
			newChannel.incrementNumClients();
            client.setIsOperator(true);
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
