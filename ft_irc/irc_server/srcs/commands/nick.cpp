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
        _reply(clientIndex, "No nickname given");
        return ;
    }

    nicknames = _getAllClientNicknames(_clients);
    if (std::find(nicknames.begin(), nicknames.end(), params) != nicknames.end())
    {
        _reply(clientIndex, "Nickname is already in use");
        return ;
    }

    // **  CHECK IF NICKNAME IS TOO LONG ** //
    if (params.length() > 9)
    {
        _reply(clientIndex, "Nickname too long");
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
            _reply(clientIndex, "Erroneous nickname");
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
        _clients[clientIndex].setIsRegistered(true);
}
