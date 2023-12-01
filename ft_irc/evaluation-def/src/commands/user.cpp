#include "../../include/Server.hpp"
#include <_ctype.h>
/*
Command: USER
Parameters: <username> <hostname> <servername> :<realname>
*/

// SPLIT STRING ACCORDING TO THIS FORMAT <username> <hostname> <servername> :<realname>
std::vector<std::string> splitString (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::vector<std::string> trimmedResult;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    if (result.size() < 4)
        return result;

    std::string realName;
    for (size_t i = 3; i < result.size(); i++)
    {
        realName += result[i];
        if (i != result.size() - 1)
            realName += " ";
    }

    for (size_t i = 0; i < 3; i++)
        trimmedResult.push_back(result[i]);

    trimmedResult.push_back(realName);
    return trimmedResult;
}

void    Server::_userCommand(std::string params, unsigned short clientIndex)
{
    std::vector<std::string> tokens;

    if (!_clients[clientIndex].getIsAuthorised())
    {
        _reply(clientIndex, "You must be authorised to use this command");
        return ;
    }

    if (params.length() < 3)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default", "USER");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    if (_clients[clientIndex].getUser().length() > 0)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_ALREADYREGISTERED, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    tokens = splitString(params, 32);

    if (tokens.size() != 4)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    // ** CHECK IF USERNAME IS VALID ** //
    for (size_t i = 0; i < tokens[0].length(); i++)
    {
        if (!std::isalpha(tokens[0][i]))
        {
            _reply(clientIndex, "Invalid username");
            return ;
        }
    }

    // ** CHECK IF REAL NAME IS VALID ** //
    if (tokens[3][0] != ':')
    {
        _reply(clientIndex, "Invalid format");
        return ;
    }

    for (size_t i = 1; i < tokens[3].length(); i++)
    {
        if (!std::isalpha(tokens[3][i]) && tokens[3][i] != 32)
        {
            _reply(clientIndex, "Invalid username");
            return ;
        }
    }

    _clients[clientIndex].setUser(tokens[0]);
    _clients[clientIndex].setFullName(tokens[3].substr(1));
    if (_clients[clientIndex].getNick().length() > 0)
    {
        _clients[clientIndex].setIsRegistered(true);
        std::string message;
        message = ":";
        message += _clients[clientIndex].getNick();
        message += "!";
        message += _clients[clientIndex].getUser();
        message += "@";
        message += "localhost";
        message += " ";
        message += "001";
        message += " ";
        message += _clients[clientIndex].getNick();
        message += " ";
        message += ":Welcome to the Internet Relay Network ";
        message += _clients[clientIndex].getNick();
        message += "!";
        message += _clients[clientIndex].getUser();
        message += "@";
        message += "localhost";
        _reply(clientIndex, message);
    }
}
