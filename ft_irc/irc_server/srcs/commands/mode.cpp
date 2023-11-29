/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:52:54 by israel            #+#    #+#             */
/*   Updated: 2023/11/29 18:12:58 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

bool    Server::_checkChannelExistsInMode(std::string params, unsigned short clientIndex)
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
    return 0;
}

bool    Server::_checkIfOperatorInMode(std::string params, unsigned short clientIndex)
{
    std::vector<std::string> tokens = _splitString(params, ' ');
    Channel *channel = _getChannelByName(tokens[0]);
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

std::vector<std::string>    Server::parseModes(std::string modeString, unsigned short clientIndex)
{
    std::vector<std::string>    modes;
    std::string                 mode;
    std::string                 flag;
    std::string                 params;
    std::string::iterator       it;
    std::string                 allowModes = "itkol+-";

    std::cout << "MODE" << std::endl;
    std::cout << params << std::endl;
    std::cout << clientIndex << std::endl;
    
    for (it = modeString.begin(); it != modeString.end(); it++)
    {
        // std::cout << "sending Unknown MODE flag" << std::endl;
        // _sendMessageToClient(":Unknown MODE flag\r\n", clientIndex);
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

void execTopic(Channel &channel, char sign)
{
    if (sign == '+')
        channel.setModeT(true);
    else if (sign == '-')
        channel.setModeT(false);
}

void execInvite(Channel &channel, char sign)
{
    if (sign == '+')
        channel.setModeI(true);
    else if (sign == '-')
        channel.setModeI(false);
}

void execKey(Channel &channel, char sign, std::string key)
{
	std::cout << "key en execkey es: |:" << key << "|" << std::endl;
    if (sign == '-')
        channel.setKey("");
    else if (sign == '+')
    {    
        if (!key.length())
            return ;
        channel.setKey(key);
    }
}

void Server::execLimit(unsigned short clientIndex, Channel &channel, char sign, std::string limit)
{
    if (!limit.length() && sign == '+')
        return ;
    else if (sign == '-')
        channel.setModeL(false);
    else if (sign == '+')
    {
        std::istringstream iss(limit);
        size_t value;
        if (!(iss >> value) || iss.fail() || iss.peek() != EOF || value > ULONG_MAX)
        {
            std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " +l " + limit + ": invalid argument";
            Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
        }
        else
        {
            channel.setModeL(true);
            channel.setLimit(value);
        }
    }
}

void Server::execOperator(unsigned short clientIndex, Channel &channel, char sign, std::string user)
{
    Client extractedUser;
    int userKey;
    bool userExists = false;
    bool userOnChannel = false;

    if (!user.length())
        return ;
    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); it++)
    {
        if (user == it->second.getNick())
        {
            userKey = it->first;
            extractedUser = it->second;
            userExists = true;
        }
    }
    if (!userExists)
    {
        std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " +o " + user + ": user doesn't exist";
            Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
        return ;
    }
    for (std::map<int, Client>::iterator it = channel.getMembers().begin(); it != channel.getMembers().end(); it++)
    {
        if (user == it->second.getNick())
            userOnChannel = true;
    }
    if (!userOnChannel)
    {
        std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " +o " + user + ": user not on channel";
            Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
        return ;
    }
    if (sign == '+')
        channel.getOperators().insert(std::make_pair(userKey, extractedUser));
    else if (sign == '-')
    {
        if (channel.getOperators().find(userKey) == channel.getOperators().end())
        {
            std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " -o " + user + ": user not operator";
                Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
        }
        else
            channel.getOperators().erase(userKey);
    }
}

void    Server::_executeModes(Channel &channel, unsigned short clientIndex, std::vector<std::string> modes, std::vector<std::string> args)
{
    std::vector<std::string>::iterator mIt;
    std::vector<std::string>::iterator aIt;

    for (mIt = modes.begin(); mIt != modes.end(); mIt++)
        std::cout << "mode: " << *mIt << std::endl;

    size_t modesLen = modes.size();
    for (size_t i = 0; i < modesLen; i++)
    {
        char sign = modes[0][0];
        char mode = modes[0][1];
        std::string arg = "";
        if (args.size())
            arg = args[0];
        if (mode == 't')
            execTopic(channel, sign);
        else if (mode == 'i')
            execInvite(channel, sign);
        else if (mode == 'k')
            execKey(channel, sign, arg);
        else if (mode == 'l')
            execLimit(clientIndex, channel, sign, arg);
        else if (mode == 'o')
            execOperator(clientIndex, channel, sign, arg);
        modes.erase(modes.begin());
        if (mode == 'o' || mode == 'l' || mode == 'k')
            if (sign == '+' && args.size())
                args.erase(args.begin());
    }
}

void    Server::_modeCommand(std::string params, unsigned short clientIndex)
{
    std::ostringstream oss;

    if (_checkChannelExistsInMode(params, clientIndex))
        return ;
    //** SPLIT PARAMS STRING TO VECTOR **//
    std::vector<std::string> tokens = _splitString(params, ' ');
    //** GET CHANNELS BY NAME **//
    Channel *channel = _getChannelByName(tokens[0]);

    //** DISPLAY MODES **//
    oss << channel->getLimit();
    if (tokens.size() == 1)
    {
        std::string message;
        message = _clients[clientIndex].getNick() + " " + channel->getName();
        if (channel->getModeL() || channel->getModeT() || channel->getModeI())
            message += " +";
        if (channel->getModeL())
            message += 'l';
        if (channel->getModeT())
            message += 't';
        if (channel->getModeI())
            message += 'i';
        if (channel->getModeL())
            message += " " + oss.str();
        Server::_message(Reply::RPL_CHANNELMODEIS, _clients[clientIndex], std::vector<std::string>(1, message));
    }
    //** PARSE AND EXEC MODES **//
    else
    {
        if (_checkIfOperatorInMode(params, clientIndex))
            return ;
        /** CREATE MODE STRING FOR PARSING  **/
        std::string modeString = tokens[1];
        /** PARSE MODES **/
        std::vector<std::string> modes = parseModes(modeString, clientIndex);

        /** CREATE ARGUMENT VECTOR TO BE USED IN EXEC LOOP  **/
        std::vector<std::string> args;
        args.assign(tokens.begin() + 2, tokens.end());

        /** EXEC MODES **/
        _executeModes(*channel, clientIndex, modes, args);
    }
}
