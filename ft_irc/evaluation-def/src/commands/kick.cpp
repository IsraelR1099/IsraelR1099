/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:59:50 by israel            #+#    #+#             */
/*   Updated: 2023/12/01 09:59:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

int  Server::_errorKickCommand(std::vector<std::string> &tokens, unsigned short clientIndex)
{
    if (tokens.size() < 3)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("461", "KICK");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return (-1);
    }
    else if (tokens[0][0] != '#')
    {
		std::string	params(tokens[0]);
		std::string prefix = _clients[clientIndex].getCustomPrefix("403", params);
		Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
		return (-1);
    }
	else if (tokens[2][0] != ':')
	{
        std::string prefix = _clients[clientIndex].getCustomPrefix("461", "KICK");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return (-1);
    }
	return (0);
}

int clientIsInChannel(Channel *channel, std::string &client)
{
    std::map<int, Client>           tmpMap = channel->getMembers();
    std::map<int, Client>::iterator itClient = tmpMap.begin();

    while (itClient != tmpMap.end())
    {
        if (itClient->second.getNick() == client)
            return (itClient->first);
        itClient++;
    }
    return (-1);
}

std::string  commentsKick(std::string params)
{
    size_t                          colonPos;
    std::string                     comments;

    colonPos = params.find(":");
    if (colonPos != std::string::npos && colonPos + 1 < params.length())
    {
        comments = params.substr(colonPos + 1);
        return (comments);
    }
    else
        comments = "Kicked";
    return (comments);
}

void    Server::_kickCommand(std::string params, unsigned short clientIndex)
{
    std::istringstream				iss(params);
    std::vector<std::string>		tokens;
    std::string						token;
	std::map<int, Client>::iterator	itClient;
    int                             socketClientRemove;
    std::string                     comments;

    if (_checkRegisteredAndParams(params, clientIndex))
        return ;
    while (std::getline(iss, token, ' '))
        tokens.push_back(token);
    comments = commentsKick(params);
    if (tokens.size() < 2)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default", "KICK");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }
    if (_errorKickCommand(tokens, clientIndex) == -1)
    {
        return ;
    }
	//Check if operator exists in clients map of Server
	itClient = this->_clients.find(clientIndex);
    if (itClient != this->_clients.end())
	{
		//Check if the channel exists in map of Server
		Channel	*tmpChannel = this->_getChannelByName(tokens[0]);

		if (tmpChannel)
		{
			//Check if this client, who is typing KICK, is an operator
            std::map<int, Client>   tmpMap = tmpChannel->getOperators();
            std::map<int, Client>::iterator itClientIn = tmpMap.find(clientIndex);
			if (itClientIn != tmpMap.end())
			{
                //Check if the client to kick is in the channel
                socketClientRemove = clientIsInChannel(tmpChannel, tokens[1]);
                if (socketClientRemove > 0)
                {
                    std::string message = ":" + itClient->second.getNick()
                        + " KICK " + tokens[0] + " " + tokens[1] + " " + comments;
                    std::map<int, Client>::iterator itClientRemove = this->_clients.find(socketClientRemove);
                    if (itClientRemove != this->_clients.end())
                    {
                        for (std::map<int, Client>::iterator it = tmpChannel->getMembers().begin(); it != tmpChannel->getMembers().end(); it++)
                            _clients[it->first].write_buffer(_clients[it->first], message); 
                        tmpChannel->removeChannelClient(itClientRemove->second);
                    }
                }
                else
                {
                    std::vector<std::string> options;
                    options.push_back(tokens[1]);
                    options.push_back(tokens[0]);
                    std::string	prefix = _clients[clientIndex].getCustomPrefix("441", options);
                    Server::_message(Reply::ERR_USERNOTINCHANNEL, _clients[clientIndex],
                            std::vector<std::string>(1, prefix));
                }
			}
			else
			{
                std::string prefix = ":" + _clients[clientIndex].getCustomPrefix("default") + " " + tokens[0];
                Server::_message(Reply::ERR_CHANOPRIVSNEEDED, _clients[clientIndex], std::vector<std::string>(1, prefix));   
			}
		}
		else
		{
			std::string	params(tokens[0]);
			std::string prefix = _clients[clientIndex].getCustomPrefix("403", params);
			Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
		}
	}
}
