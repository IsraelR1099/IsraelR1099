#include "../../include/Server.hpp"
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
    int rc;
    std::vector<std::string> tokens;

    if (!_clients[clientIndex].getIsAuthorised())
    {
        _reply(clientIndex, "You must be authorised to use this command");
        return ;
    }

    if (params.length() < 3)
    {
        _reply(clientIndex, "Not enough parameters");
        return ;
    }

    if (_clients[clientIndex].getUser().length() > 0)
    {
        _reply(clientIndex, "You may not reregister");
        return ;
    }

    tokens = splitString(params, 32);
    std::cout << "tokens length: " << tokens.size() << std::endl;
    for (size_t i = 0; i < tokens.size(); i++)
    {
        std::cout << "token " << i << ": " << tokens[i] << std::endl;
    }

    if (tokens.size() != 4)
    {
        _reply(clientIndex, "Not enough parameters");
        return ;
    }





    // CHECK IF THIS FORMAT IS CORRECT <username> <hostname> <servername> :<realname>
    // if (tokens[3][0] != ';')
    // {
    //     rc = send(_clients[clientIndex].getSocketNumber(), "Invalid format\n", 15, 0);
    //     if (rc < 0)
    //         throw Server::ServerError("send() failed");
    //     return ;
    // }


    // ** CHECK IF USERNAME IS VALID ** //
    for (size_t i = 0; i < tokens[0].length(); i++)
    {
        if (!isalpha(tokens[0][i]))
        {
            rc = send(_clients[clientIndex].getSocketNumber(), "Invalid username\n", 17, 0);
            if (rc < 0)
                throw Server::ServerError("send() failed");
        }
    }

    // ** CHECK IF REAL NAME IS VALID ** //
    if (tokens[3][0] != ':')
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "Invalid format\n", 15, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
        return ;
    }

    for (size_t i = 1; i < tokens[3].length(); i++)
    {
        if (!isalpha(tokens[3][i]) && tokens[3][i] != 32)
        {
            rc = send(_clients[clientIndex].getSocketNumber(), "Bad format\n", 11, 0);
            if (rc < 0)
                throw Server::ServerError("send() failed");
        }
    }

    _clients[clientIndex].setUser(tokens[0]);
    _clients[clientIndex].setFullName(tokens[3].substr(1));
    if (_clients[clientIndex].getNick().length() > 0)
        _clients[clientIndex].setIsRegistered(true);
    std::cout << "full name client: " << _clients[clientIndex].getFullName() << std::endl;
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
