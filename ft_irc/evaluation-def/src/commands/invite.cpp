#include "../../include/Server.hpp"

void    Server::_inviteCommand(std::string params, unsigned short clientIndex)
{
    int targetIndex = -1;
    if (_checkRegisteredAndParams(params, clientIndex))
        return ;

    // Check if channel exists
    std::vector<std::string> tokens = _splitString(params, ' ');
    Channel *channel = _getChannelByName(tokens[1]);
    if (!channel)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default") + " " + tokens[0];
        Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }
    // Check if we(sender) are in channel
    if (!channel->isClientInChannel(clientIndex))
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default") + " " + tokens[0];
        Server::_message(Reply::ERR_NOTONCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }
    // Check if target client exists
    std::map<int, Client>::iterator it = _clients.end();
    for (it = _clients.begin(); it != _clients.end(); it++)
    {
        if (it->second.getNick() == tokens[0] && it->first != clientIndex)
            targetIndex = it->first;
    }
    if (targetIndex == -1)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default") + " " + tokens[0];
        Server::_message(Reply::ERR_NOSUCHNICK, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }
    // check if oper
    if (channel->getModeI() && channel->getOperators().find(clientIndex) == channel->getOperators().end())
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default") + " " + tokens[0];
        Server::_message(Reply::ERR_CHANOPRIVSNEEDED, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }
    if (!channel->isClientInChannel(targetIndex))
    {
        std::string message = _clients[clientIndex].getNick() + " " + tokens[0] + " " + tokens[1];
        Server::_message(Reply::RPL_INVITING, _clients[clientIndex], std::vector<std::string>(1, message));
        // message = "INVITE :" + _clients[clientIndex].getNick() + " " + tokens[1];
        message = ":" + _clients[clientIndex].getNick() + " INVITE " + tokens[0] + " " + tokens[1];
        _reply(targetIndex, message);
        channel->getInvitees().insert(std::make_pair(targetIndex, _clients[targetIndex]));
    }
    else
    {
        std::string message = _clients[clientIndex].getNick() + " " + tokens[1] + " " + tokens[0];
        Server::_message(Reply::ERR_USERONCHANNEL, _clients[clientIndex], std::vector<std::string>(1, message));
    }
}
