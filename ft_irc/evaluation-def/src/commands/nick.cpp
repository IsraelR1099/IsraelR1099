#include "../../include/Server.hpp"

void	Server::_nickCommand(std::string params, unsigned short clientIndex)
{
    std::vector<std::string>    nicknames;
    // int rc;
    std::string errorMessage;

    if (!_clients[clientIndex].getIsAuthorised())
    {
        _reply(clientIndex, "You must be authorised to use this command");
        return ;
    }

    if (!params.length())
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_NONICKNAMEGIVEN, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    nicknames = _getAllClientNicknames(_clients);
    if (std::find(nicknames.begin(), nicknames.end(), params) != nicknames.end())
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += params;
        Server::_message(Reply::ERR_NICKNAMEINUSE, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    // **  CHECK IF NICKNAME IS TOO LONG ** //
    if (params.length() > 9)
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        prefix += " ";
        prefix += params;
        Server::_message(Reply::ERR_ERRONEOUSNICKNAME, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return ;
    }

    bool badChar = false;
    for (size_t i = 0; i < params.length(); i++)
    {
        if (i == 0 && (params[0] >= '0' && params[0] <= '9'))
            badChar = true;
        else if (!((params[i] >= 'a' && params[i] <= 'z')
                    || (params[i] >= 'A' && params[i] <= 'Z')
                    || (params[i] >= '0' && params[i] <= '9') 
                    || (params[i] == '|') || (params[i] == '{')
                    || (params[i] == '}') || (params[i] == '|')
                    || (params[i] == '_')))
            badChar = true;
        if (badChar)
        {
            std::string prefix = _clients[clientIndex].getCustomPrefix("default");
            prefix += " ";
            prefix += params;
            Server::_message(Reply::ERR_ERRONEOUSNICKNAME, _clients[clientIndex], std::vector<std::string>(1, prefix));
            return ;
        }
    }

    if (_clients[clientIndex].getIsAuthorised())
        _clients[clientIndex].setNick(params);
    else
    {
        _reply(clientIndex, "You must be authorised to use this command");
        return ;
    }
    
    if (_clients[clientIndex].getUser().length() > 0)
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
