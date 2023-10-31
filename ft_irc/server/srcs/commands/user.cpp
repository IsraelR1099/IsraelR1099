#include "../../include/Server.hpp"

void    Server::_userCommand(std::string params, unsigned short clientIndex)
{
    if (!_clients[clientIndex].getIsAuthorised())
    {
        int rc = send(_clients[clientIndex].getSocketNumber(), "You must be authorised to use this command\n", 44, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
        return ;
    }
    _clients[clientIndex].setUser(params);
    if (_clients[clientIndex].getNick().length() > 0)
        _clients[clientIndex].setIsRegistered(true);
}
