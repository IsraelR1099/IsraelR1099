/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:10:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/27 14:00:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_topicCommand(std::string params, unsigned short clientIndex)
{
    if (_checkRegisteredAndParams(params, clientIndex))
        return ;
    std::vector<std::string> tokens = _splitString(params, ' ');
    Channel *channel = _getChannelByName(tokens[0]);
    if (!channel)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += tokens[0];
        Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }
    else if (!channel->isClientInChannel(clientIndex))
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += tokens[0];
        Server::_message(Reply::ERR_NOTONCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    else if (tokens.size() == 1)
    {
        std::string message = _clients[clientIndex].getNick() + " " + tokens[0] + " :";
        std::string setAtMessage = _clients[clientIndex].getNick() + " " + tokens[0] + " " + channel->getTopicChanger() + " " + channel->getTopicChangeTime();
        std::string topic = channel->getTopic();
        if (topic.length())
            message += topic;
        Server::_message(Reply::RPL_TOPIC, _clients[clientIndex], std::vector<std::string>(1, message));
        Server::_message(Reply::RPL_TOPICWHOTIME, _clients[clientIndex], std::vector<std::string>(1, setAtMessage));
        return ;
    }
    else if (tokens.size() > 1)
    {
        if (tokens[1][0] == ':')
        {
            if (channel->getModeT())
            {
                if (channel->getOperators().find(clientIndex) == channel->getOperators().end())
                {
                    std::string prefix = _clients[clientIndex].getCustomPrefix("default");
                    prefix += " ";
                    prefix += tokens[0];
                    Server::_message(Reply::ERR_CHANOPRIVSNEEDED, _clients[clientIndex], std::vector<std::string>(1, prefix));
                    return ;
                }
            }
            if (tokens[1][1] == '\0')
                channel->setTopic(params.substr(params.find(":") + 1));
            else
                channel->setTopic(params.substr(params.find(":") + 1));
            channel->setTopicChanger(_clients[clientIndex].getNick());
            time_t currentTime = time(NULL);
            channel->setTopicChangeTime(ctime(&currentTime));
            std::map<int, Client> members = channel->getMembers();
            for (std::map<int, Client>::iterator it = members.begin(); it != members.end(); it++)
            {
                std::string message = "TOPIC change " + channel->getName() + ": ";
                std::string topic = channel->getTopic();
                if (topic.length())
                    message +=  topic;
                _clients[it->first].write_buffer(_clients[it->first], message);
            }
        }
        else
            _reply(clientIndex, "Invalid format");
    }

}
