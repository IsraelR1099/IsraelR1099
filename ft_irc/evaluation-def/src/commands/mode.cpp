/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:52:54 by israel            #+#    #+#             */
/*   Updated: 2023/12/01 09:35:07 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

std::string getLastOccurrences(const std::string& input) {
    std::string result;
    char mode;

    
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == '+' || input[i] == '-')
            mode = input[i];
        if (input[i] != '-' && input[i] != '+')
        {
            char currentChar = input[i];
            size_t lastPosition = input.rfind(currentChar);
            if (i == lastPosition) {
                result += std::string(1, mode) + currentChar;
            }
        }

        // Check if the current position is the last occurrence of the character
    }
    return result;
}

std::string removeExcessiveSigns(const std::string& input)
{
    char sign = input[0];
    std::string result = std::string(1, sign);
    for (size_t i = 1; i < input.length(); i++)
    {
        if (input[i] == '+' || input[i] == '-')
        {
            if (sign == input[i])
            {
                sign = input[i];
                continue;
                
            }
                
        }
        result.push_back(input[i]);
        
    }
    return result;
}

int checkIfAdd(Channel &channel, char sign, char mode)
{
    if (mode == 't')
    {
        if (channel.getModeT())
        {
            if (sign == '+')
                return 1;
        }
        else
        {
            if (sign == '-')
                return 1;
        }
            
    }
    else if (mode == 'i')
    {
        if (channel.getModeI())
        {
            if (sign == '+')
                return 1;
        }
        else 
        {
            if (sign == '-')
                return 1;
        }
        
    }
    return (0);
}

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
        std::string prefix = ":" + _clients[clientIndex].getCustomPrefix("default") + " " + tokens[0];
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

    
    for (it = modeString.begin(); it != modeString.end(); it++)
    {
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
            std::string modechar = std::string(1, *it);
            std::string prefix = _clients[clientIndex].getCustomPrefix("472", modechar);
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

int execKey(Channel &channel, char sign, std::string key)
{
    if (sign == '-')
        channel.setKey("");
    else if (sign == '+')
    {    
        if (!key.length())
            return 1;
        channel.setKey(key);
    }
    return 0;
}

int Server::execLimit(unsigned short clientIndex, Channel &channel, char sign, std::string limit)
{
    if (!limit.length() && sign == '+')
        return 1;
    else if (sign == '-')
        channel.setModeL(false);
    else if (sign == '+')
    {
        std::istringstream iss(limit);
        size_t value;
        if (!(iss >> value) || iss.fail() || iss.peek() != EOF || value > ULONG_MAX)
        {       
            std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " +l " + limit + " :invalid argument";
            Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
            return 1;
        }
        else
        {
            channel.setModeL(true);
            channel.setLimit(value);
        }
    }
    return 0;
}

int Server::execOperator(unsigned short clientIndex, Channel &channel, char sign, std::string user)
{
    Client extractedUser;
    int userKey;
    bool userExists = false;
    bool userOnChannel = false;
    
    if (!user.length())
        return 1;
    
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
        std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " +o " + user + " :user doesn't exist";
            Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
        return 1;
    }
    for (std::map<int, Client>::iterator it = channel.getMembers().begin(); it != channel.getMembers().end(); it++)
    {
        if (user == it->second.getNick())
            userOnChannel = true;
    }
    if (!userOnChannel)
    {
        std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " +o " + user + " :user not on channel";
            Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
        return 1;
    }
    if (sign == '+')
        channel.getOperators().insert(std::make_pair(userKey, extractedUser));
    else if (sign == '-')
    {
        if (channel.getOperators().find(userKey) == channel.getOperators().end())
        {
            std::string message = _clients[clientIndex].getNick() + " " + channel.getName() + " -o " + user + " :user not operator";
                Server::_message(Reply::ERR_INVALIDMODEPARAM, _clients[clientIndex], std::vector<std::string>(1, message));
            return 1;
        }
        else
            channel.getOperators().erase(userKey);
    }
    return 0;
}

void    Server::_executeModes(Channel &channel, unsigned short clientIndex, std::vector<std::string> modes, std::vector<std::string> args)
{
    std::vector<std::string>::iterator mIt;
    std::vector<std::string>::iterator aIt;
    std::string messageModes = "";
    std::string messageArgs = "";
    std::string modeString;
    // char mode = '+';
    

    // messageModes.assign(modes.begin(), modes.end());
    // messageArgs.assign(args.begin(), args.end());


    size_t modesLen = modes.size();
    for (size_t i = 0; i < modesLen; i++)
    {
        char sign = modes[0][0];
        char mode = modes[0][1];
        // bool execFailed = false;
        std::string arg = "";
        if (args.size())
            arg = args[0];
        if (mode == 't')
        {
            if (!checkIfAdd(channel, sign, mode))
                messageModes += std::string(1, sign) + mode;
            execTopic(channel, sign);
        }
        else if (mode == 'i')
        {
            if (!checkIfAdd(channel, sign, mode))
                messageModes += std::string(1, sign) + mode;
            execInvite(channel, sign);
        }
        else if (mode == 'k')
        {
            execKey(channel, sign, arg);
        }
        else if (mode == 'l')
        {
            execLimit(clientIndex, channel, sign, arg);
        }
        else if (mode == 'o')
        {
            execOperator(clientIndex, channel, sign, arg);
                // messageModes += std::string(1, sign) + mode;
        }
        // if (!execFailed)
        //     messageModes += std::string(1, sign) + mode;
        modes.erase(modes.begin());
        if ((mode == 'o' || mode == 'l' || mode == 'k'))
        {
            if (sign == '+' && args.size())
            {
                args.erase(args.begin());
                // if (!execFailed)
                //     messageArgs += arg + " ";
            }
        }
    }
    if (messageModes.length())
    {
        for (std::map<int, Client>::iterator it = channel.getMembers().begin(); it != channel.getMembers().end(); it++)
        {
            std::string message = ":" + _clients[clientIndex].getNick() + " MODE " + channel.getName();
            message += " " + removeExcessiveSigns(getLastOccurrences(messageModes)) + " " + messageArgs;
            _clients[it->first].write_buffer(_clients[it->first], message);
        }
    }
}

void    Server::_modeCommand(std::string params, unsigned short clientIndex)
{
    if (_checkChannelExistsInMode(params, clientIndex))
        return ;
        
    //** SPLIT PARAMS STRING TO VECTOR **//
    std::vector<std::string> tokens = _splitString(params, ' ');
    //** GET CHANNELS BY NAME **//
    Channel *channel = _getChannelByName(tokens[0]);

    //** DISPLAY MODES **//
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
            message += " " + std::to_string(channel->getLimit());
        
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
