/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:33:21 by dbekic            #+#    #+#             */
/*   Updated: 2023/12/01 09:17:23 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include "../../include/Channel.hpp"

static std::string removeSpaces(std::string str)
{
    std::string newString;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != 32)
            newString.push_back(str[i]);
    }
    return (newString);
}

void    Server::_partCommand(std::string params, unsigned short clientIndex)
{
    if (_checkRegisteredAndParams(params, clientIndex))
        return ;

    std::vector<std::string> tokens = _splitString(params, ' ');
    std::string channelsToSplit = removeSpaces(tokens[0]);
    std::vector<std::string> channels = _splitString(channelsToSplit, ',');
    std::string comment;

    // if (tokens.size() > 1)
    // {
    //     comment = tokens[1].substr(1);
    // }
    for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); it++)
    {
        Channel *tmp = _getChannelByName(*it);
        if (!tmp)
        {
            std::string prefix = _clients[clientIndex].getNick() + " " + *it;
            Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
            continue ;
        }
        else if (tmp->getMembers().find(clientIndex) == tmp->getMembers().end())
        {
            std::string prefix = _clients[clientIndex].getNick() + " " + *it;
            Server::_message(Reply::ERR_NOTONCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
            continue ;
        }
        std::map<int, Client> members = tmp->getMembers();
        for (std::map<int, Client>::iterator it = members.begin(); it != members.end(); it++)
        {
            std::string message = ":" + _clients[clientIndex].getNick() + " PART " + tmp->getName();
            if (comment.length())
                message += " " + comment;
            _clients[it->first].write_buffer(_clients[it->first], message); 
        }
        tmp->removeChannelClient(_clients[clientIndex]);
    }
}
