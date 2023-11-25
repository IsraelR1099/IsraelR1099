/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:52:54 by israel            #+#    #+#             */
/*   Updated: 2023/11/25 20:47:03 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

bool    Server::_checkChannelAndOperatorInMode(std::string params, unsigned short clientIndex)
{
    if (_checkRegisteredAndParams(params, clientIndex))
        return 1;

    std::vector<std::string> tokens = _splitString(params, ' ');

    Channel *channel = _getChannelByName(tokens[0]);
    if (!channel)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += tokens[0];
        Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return 1;
    }
    std::map<int, Client> ops = channel->getOperators();
    bool isOp = false;
    for (std::map<int, Client>::iterator it = ops.begin(); it != ops.end(); it++)
    {
        if (it->second.getNick() == _clients[clientIndex].getNick())
            isOp = true;
    }
    if (!isOp)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += tokens[0];
        Server::_message(Reply::ERR_CHANOPRIVSNEEDED, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return 1;
    }
    return 0;
}
           /* if (*it == '+' || *it == '-')
            {
                if (mode.length() > 0)
                    modes.push_back(mode);
                mode = *it;
                flag = *it;
            }
            else
            {
                mode += *it;
                flag += *it;
                modes.push_back(flag);
            }*/

std::vector<std::string>    Server::parseModes(std::string modeString, unsigned short clientIndex)
{
    std::vector<std::string>    modes;
    std::string                 mode;
    std::string                 flag;
    std::string                 params;
    std::string::iterator       it;
    std::string                 allowModes = "itkol+-";

    for (it = modeString.begin(); it != modeString.end(); it++)
    {
        if (*it == '+' || *it == '-')
            mode = *it;
        if (allowModes.find(*it) != std::string::npos)
        {
            if (*it != '+' && *it != '-')
                modes.push_back(mode + *it);
        }
        else
        {
            std::cout << ANSI::red <<
                "ERR_UNKNOWNMODE: " << *it << ANSI::reset << std::endl;
            std::string modechar = std::string(1, *it);
            std::cout << "modechar: " << modechar << std::endl;
            std::string prefix = _clients[clientIndex].getCustomPrefix("472", modechar);
            std::cout << "prefix: " << prefix << std::endl;
            Server::_message(Reply::ERR_UNKNOWNMODE, _clients[clientIndex], std::vector<std::string>(1, prefix));
        }
    }
    return (modes);
}

void    Server::_modeCommand(std::string params, unsigned short clientIndex)
{
    std::string                 modeString;
    std::vector<std::string>    modes;

    if (_checkChannelAndOperatorInMode(params, clientIndex))
        return ;
    std::vector<std::string> tokens = _splitString(params, ' ');

    modeString = tokens[1];
    modes = parseModes(modeString, clientIndex);
}
