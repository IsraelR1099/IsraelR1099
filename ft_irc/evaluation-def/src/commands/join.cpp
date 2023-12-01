/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:08:09 by dbekic            #+#    #+#             */
/*   Updated: 2023/11/30 12:08:42 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_joinToChannel(unsigned short clientIndex, std::string channelName)
{
    std::map<int, Channel>::iterator    it;
    Channel *channel = _getChannelByName(channelName);
    if (channel)
        channel->addClient(_clients[clientIndex], clientIndex, false);
    else
    {
        Channel newChannel(channelName);
        newChannel.addClient(_clients[clientIndex], clientIndex, true);
        this->_channels.insert(std::make_pair(this->_numChannels, newChannel));
        newChannel.incrementNumClients();
        this->_incrementChannels();
        channel = _getChannelByName(channelName);
    }
    for (std::map<int, Client>::iterator it = channel->getMembers().begin(); it != channel->getMembers().end(); it++)
    {
        std::string fullMessage = ":" + _clients[clientIndex].getNick() + "!" + it->second.getUser() + "@" + it->second.getHost() + " JOIN " + ":" + channelName;
        _clients[it->first].write_buffer(_clients[it->first], fullMessage); 
    }
    if (channel->getTopic().length()) 
    {
        std::string message = _clients[clientIndex].getNick() + " " + channelName + " :" + channel->getTopic();
        Server::_message(Reply::RPL_TOPIC, _clients[clientIndex], std::vector<std::string>(1, message));
    }
    for (std::map<int, Client>::iterator it2 = channel->getMembers().begin(); it2 != channel->getMembers().end(); it2++)
    {
        std::string nameReply = _clients[clientIndex].getNick() + " = " + channelName + " :";
        if (channel->getOperators().find(it2->first) != channel->getOperators().end())
            nameReply += '@';
        nameReply += it2->second.getNick();
        Server::_message(Reply::RPL_NAMREPLY, _clients[clientIndex], std::vector<std::string>(1, nameReply));
    }
    std::string endOfNamesReply = _clients[clientIndex].getNick() + " " + channelName + " :End of /NAMES list";
    Server::_message(Reply::RPL_ENDOFNAMES, _clients[clientIndex], std::vector<std::string>(1, endOfNamesReply));
}

int    Server::_checkJoinConditions(unsigned short clientIndex, Channel &channel, std::string key)
{
    if (channel.getModeL() && channel.getNumClients() >= channel.getLimit())
    {
        std::string prefix = _clients[clientIndex].getNick() + " " + channel.getName();
        Server::_message(Reply::ERR_CHANNELISFULL, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return 1;
    }
    else if (channel.getModeI() && !channel.isClientInvited(_clients[clientIndex]))
    {
        std::string prefix = _clients[clientIndex].getNick() + " " + channel.getName();
        Server::_message(Reply::ERR_INVITEONLYCHAN, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return 1;
    }
    else if (channel.getKey().length() && channel.getKey() != key)
    {
        std::string prefix = _clients[clientIndex].getNick() + " " + channel.getName();
        Server::_message(Reply::ERR_BADCHANNELKEY, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return 1;
    }
    return 0;
}


void    Server::_joinCommand(std::string params, unsigned short clientIndex)
{
    if (_checkRegisteredAndParams(params, clientIndex))
        return ;

    (void)clientIndex;

    std::vector<std::string> tokens = _splitString(params, ' ');
    std::vector<std::string> channels = _splitString(tokens[0], ',');
    // make keys vector if token[1] exists  (token[1] is keys)
    std::vector<std::string> keys;
    if (tokens.size() > 1)
        keys = _splitString(tokens[1], ',');
    else
    {
        for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); it++)
            keys.push_back("");
    }   

    for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); it++)
    {
        if ((*it)[0] != '#')
        {
            std::string prefix = _clients[clientIndex].getNick() + " " + *it;
            Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
            continue ;
        }
        Channel *channel = _getChannelByName(*it);
        if (!channel)
            _joinToChannel(clientIndex, *it);
        else if (channel->getMembers().find(clientIndex) != channel->getMembers().end())  // already in chan
            continue ;
        else if (_checkJoinConditions(clientIndex, *channel, keys[0]))
            continue ;
        else
            _joinToChannel(clientIndex, channel->getName());
        if (!keys.empty())
            keys.erase(keys.begin());
    }
}
