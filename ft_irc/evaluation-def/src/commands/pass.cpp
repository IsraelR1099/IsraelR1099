#include "../../include/Server.hpp"

void	Server::_passCommand(std::string params, unsigned short clientIndex)
{
    if (!params.length())
    {
        // std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, "*"));
    }
    else if (_clients[clientIndex].getIsRegistered())
    {
        std::string prefix = _clients[clientIndex].getCustomPrefix("default");
        Server::_message(Reply::ERR_ALREADYREGISTERED, _clients[clientIndex], std::vector<std::string>(1, prefix));
    }
    else if (params == _m_password)
        _clients[clientIndex].setIsAuthorised(true);
    else
    {
        if (_clients[clientIndex].getIsAuthorised())
            _clients[clientIndex].setIsAuthorised(false);
        Server::_message(Reply::ERR_PASSWDMISMATCH, _clients[clientIndex], std::vector<std::string>(1, "*"));
    }   
}
