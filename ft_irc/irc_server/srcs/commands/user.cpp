#include "../../include/Server.hpp"
/*
Command: USER
Parameters: <username> <hostname> <servername> :<realname>
*/

// SPLIT STRING ACCORDING TO THIS FORMAT <username> <hostname> <servername> :<realname>
std::vector<std::string> splitString (const std::string &s, char delim) {
    std::vector<std::string>    result;
    std::vector<std::string>    trimmedResult;
    std::stringstream           ss(s);
    std::string                 item;

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
    // ** CHECK IF USERNAME IS VALID ** //
    for (size_t i = 0; i < tokens[0].length(); i++)
    {
        if (!isalpha(tokens[0][i]))
        {
            _reply(clientIndex, "Bad format");
            return ;
        }
    }

    // ** CHECK IF REAL NAME IS VALID ** //
    if (tokens[3][0] != ':')
    {
        _reply(clientIndex, "Bad format");
        return ;
    }
    for (size_t i = 1; i < tokens[3].length(); i++)
    {
        if (!isalpha(tokens[3][i]) && tokens[3][i] != 32)
        {
            _reply(clientIndex, "Bad format");
            return ;
        }
    }
    _clients[clientIndex].setUser(tokens[0]);
    _clients[clientIndex].setFullName(tokens[3].substr(1));
    if (_clients[clientIndex].getNick().length() > 0)
        _clients[clientIndex].setIsRegistered(true);
    std::cout << "full name client: " << _clients[clientIndex].getFullName() << std::endl;

    std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);

	if (itClient != _clients.end())
	{
		std::string	prefix = itClient->second.getCustomPrefix("001");
		Server::_message(Reply::RPL_WELCOME, itClient->second, std::vector<std::string>(1, prefix));
	}
}
