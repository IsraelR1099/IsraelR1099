#include "../../include/Server.hpp"

void	Server::_passCommand(std::string params, Client &client)
{
    int rc;

    if (client.getIsAuthorised())
    {
        rc = send(client.getSocketNumber(), "You are already authorised\n", 27, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
    else if (params == _m_password)
        client.setIsAuthorised(true);
    else
    {
        rc = send(client.getSocketNumber(), "Wrong password\n", 15, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }   
}
