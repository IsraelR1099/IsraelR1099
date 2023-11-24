/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:16:55 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/24 10:22:36 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include <sstream>

std::string removeSpaces(std::string str)
{
    std::string newString;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != 32)
            newString.push_back(str[i]);
    }
    return (newString);
}

void    Server::_sendPrivMsgToClient(std::string target, std::string message, unsigned short clientIndex)
{
    bool nicknameNotFound = true;
    int rc;

    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        // if nick of client in iter matches client in PRIVMSG
        if (it->second.getNick() == target)
        {
            nicknameNotFound = false;
            message += "\n";
            // send
            rc = send(it->second.getSocketNumber(), message.c_str(), message.length(), 0);
            if (rc < 0)
                throw Server::ServerError("send() failed");
        }
    }
    if (nicknameNotFound)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += target;
        Server::_message(Reply::ERR_NOSUCHNICK, _clients[clientIndex], std::vector<std::string>(1, prefix));
    }
}

void Server::_sendPrivMsgToChannel(std::string target, std::string message, unsigned short clientIndex)
{
    bool channelNameNotFound = true;
    int rc;


    for (std::map<int, Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it)
    {
        if (it->second.getName().substr(1) == target.substr(1))
        {
            channelNameNotFound = false;
            std::map<int, Client> members = it->second.getMembers();
            if (members.find(clientIndex) == members.end())
            {
                std::string prefix = _clients[clientIndex].getCustomPrefix("default");
                prefix += " ";
                prefix += it->second.getName();
                Server::_message(Reply::ERR_NOTONCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
                return ;
            }
            message += "\r\n";
            for (std::map<int, Client>::iterator it = members.begin(); it != members.end(); ++it)
            {
                rc = send(it->second.getSocketNumber(), message.c_str(), message.length(), 0);
                if (rc < 0)
                    throw Server::ServerError("send() failed");
            }
        }
    }
    if (channelNameNotFound)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += target;
        Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
    }
}


void	Server::_privmsgCommand(std::string params, unsigned short clientIndex)
{
    if (!_clients[clientIndex].getIsRegistered())
    {
        int rc = send(_clients[clientIndex].getSocketNumber(), "You must register to use this command\n", 39, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
        return ;
    }
    if (!params.length())
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_NOTEXTTOSEND, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }


    size_t colonPos = params.find(":");
    if (colonPos == std::string::npos) {
        _sendMessageToClient("Bad format\r\n", clientIndex);
        return ;
    }
    if (params[0] == ':')
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_NORECIPIENT, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    std::string targetsString = params.substr(0, colonPos - 1);
    targetsString = removeSpaces(targetsString);
    std::string message = params.substr(colonPos + 1);
    std::vector<std::string> targets = _splitString(targetsString, ',');



    for (size_t i = 0; i < targets.size(); i++)
    {
        if (targets[i][0] == '#')
            _sendPrivMsgToChannel(targets[i], message, clientIndex);
        else
            _sendPrivMsgToClient(targets[i], message, clientIndex);
    }

}
