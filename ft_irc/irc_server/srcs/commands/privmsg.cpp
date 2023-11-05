#include "../../include/Server.hpp"
#include <sstream>

void    sendToClient(std::vector<std::string> tokens, std::map<int, Client> &clients, unsigned short clientIndex)
{
    bool nicknameNotFound = true;
    int rc;

    for (std::map<int, Client>::iterator it = clients.begin(); it != clients.end(); ++it)
    {
        // if nick of client in iter matches client in PRIVMSG
        if (it->second.getNick() == tokens[0])
        {
            nicknameNotFound = false;       
            std::string message = tokens[1];
            // concatenate message
            for (size_t i = 2; i < tokens.size(); ++i)
                message += " " + tokens[i];
            message += "\n";
            // send
            rc = send(it->second.getSocketNumber(), message.c_str(), message.length(), 0);
            if (rc < 0)
                throw Server::ServerError("send() failed");
        }
    }
    if (nicknameNotFound)
    {
        rc = send(clients[clientIndex].getSocketNumber(), "No such nickname\n", 17, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
}



// void sendToChannel(std::vector<std::string> tokens, std::map<int, Client> &clients, unsigned short clientIndex)
// {
//     // check if channel exists from tokens[0], similar to nickname finding, except for getNick() we getChannelName()
//     // for client in channelClients, send to client.getSocketNumber();
// }

void	Server::_privmsgCommand(std::string params, unsigned short clientIndex)
{
    std::vector<std::string>    nicknames;
    // bool nicknameNotFound = true;

    if (!_clients[clientIndex].getIsRegistered())
    {
        int rc = send(_clients[clientIndex].getSocketNumber(), "You must register to use this command\n", 39, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
        return ;
    }

    nicknames = _getAllClientNicknames(_clients);

    std::istringstream iss(params);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) 
        tokens.push_back(token);
    
    if (tokens[0][0] != '#')
        sendToClient(tokens, _clients, clientIndex);
    // else
    //     sendToChannel()

}
