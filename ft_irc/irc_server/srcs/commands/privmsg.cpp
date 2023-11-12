#include "../../include/Server.hpp"
#include <sstream>

std::string removeSpaces(std::string str)
{
    std::string newString;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            newString.push_back(str[i]);
    }
    return (newString);
}

void    sendToClient(std::string target, std::string message, std::map<int, Client> &clients, unsigned short clientIndex)
{
    bool    nicknameNotFound = true;
    int     rc;

    for (std::map<int, Client>::iterator it = clients.begin(); it != clients.end(); ++it)
    {
        // if nick of client in iter matches client in PRIVMSG
        if (it->second.getNick() == target)
        {
            nicknameNotFound = false;
            message += "\n";
            //send
            rc = send(it->second.getSocketNumber(), message.c_str(), message.length(), 0);
            if (rc < 0)
                throw Server::ServerError("send() failed");
        }
    }
    if (nicknameNotFound)
    {
        rc = send(clients[clientIndex].getSocketNumber(), "No such nickname\n", 17, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
}

void    sendToChannel(std::string target, std::string message, std::map<int, Client> &clients, std::map<int, Channel> &channels, unsigned short clientIndex)
{
    bool    channelNotFound = true;
    int     rc;

    for (std::map<int, Channel>::iterator it = channels.begin(); it != channels.end(); ++it)
    {
        if (it->second.getName().substr(1) == target.substr(1))
        {
            channelNotFound = false;
            std::map<int, Client> members = it->second.getMembers();
            message += "\r\n";
            for (std::map<int, Client>::iterator it = members.begin(); it != members.end(); ++it)
            {
                rc = send(it->second.getSocketNumber(), message.c_str(), message.length(), 0);
                if (rc < 0)
                    throw Server::ServerError("send() failed");
            }
        }
    }
    if (channelNotFound)
    {
        rc = send(clients[clientIndex].getSocketNumber(), "No such channel\n", 17, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
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
    size_t  colonPos = params.find(':');
    if (colonPos == std::string::npos)
    {
        _sendMessageToClient("Bad format\n", clientIndex);
        return ;
    }
    std::string targetsString = params.substr(0, colonPos - 1);
    targetsString = removeSpaces(targetsString);
    std::string message = params.substr(colonPos + 1);
    std::vector<std::string> targets = _splitString(targetsString, ',');

    for(size_t i = 0; i < targets.size(); i++)
    {
        if (targets[i][0] == '#')
            sendToChannel(targets[i], message, _clients, _channels, clientIndex);
        else
            sendToClient(targets[i], message, _clients, clientIndex);
    }
}
