#include "../../include/Server.hpp"

void	Server::_passCommand(std::string params, unsigned short clientIndex)
{
    int rc;

    if (_clients[clientIndex].getIsAuthorised())
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "You are already authorised\r\n", 28, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
    else if (params == m_password)
        _clients[clientIndex].setIsAuthorised(true);
    else
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "Wrong password\r\n", 16, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
}
