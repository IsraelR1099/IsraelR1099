/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:09:57 by israel            #+#    #+#             */
/*   Updated: 2023/11/03 12:59:12 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

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
            _sendMessageToClient("ERR_NOTREGISTERED :You have not registered\r\n", clientIndex);
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
            it->second.addClient(client, clientIndex, false);
        }
        else
        {
            Channel newChannel(channelName);
            _channels.insert(std::make_pair(0, newChannel));
            newChannel.addClient(client, clientIndex, true);
            client.setIsOperator(true);
        }
    }
    else
    {
        std::cout << "Client not found" << std::endl;
        return ;
    }

    std::cout << "Client index: " << clientIndex << std::endl;
}

void    Server::_joinCommand(std::string params, unsigned short clientIndex)
{
    std::vector<std::string>    paramsVector;
    std::istringstream          iss(params);
    std::string                 token;

    while (iss >> token)
        paramsVector.push_back(token);
    if (paramsVector.size() < 1)
    {
        std::cout << ANSI::red <<
        "ERR_NEEDMOREPARAMS :Not enough parameters" <<
        ANSI::reset << std::endl;
        _sendMessageToClient("ERR_NEEDMOREPARAMS :Not enough parameters\r\n", clientIndex);
    }
    else if (paramsVector[0][0] != '#')
    {
        std::cout << ANSI::red <<
        "ERR_NOSUCHCHANNEL :No such channel" <<
        ANSI::reset << std::endl;
        _sendMessageToClient("ERR_NOSUCHCHANNEL :No such channel\r\n", clientIndex);
    }
    else
    {
        std::cout << ANSI::green <<
        "JOIN :Joining channel " << paramsVector[0] <<
        ANSI::reset << std::endl;
        _joinChannel(paramsVector[0], clientIndex);
    }
}
