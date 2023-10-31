/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:43:57 by israel            #+#    #+#             */
/*   Updated: 2023/10/31 17:44:29 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"
#include <sstream>

void	Server::_privmsgCommand(std::string params, unsigned short clientIndex)
{
    std::vector<std::string>    nicknames;
    bool nicknameNotFound = true;
    int rc;

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

    std::cout << _clients[clientIndex].getNick() << std::endl;
    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        if (it->second.getNick() == tokens[0])
        {
            nicknameNotFound = false;
            std::string result = tokens[1];

            for (size_t i = 2; i < tokens.size(); ++i)
                result += " " + tokens[i];
            result += "\n";
            rc = send(it->second.getSocketNumber(), result.c_str(), result.length(), 0);
            if (rc < 0)
                throw Server::ServerError("send() failed");
        }
    }
    if (nicknameNotFound) {
        rc = send(_clients[clientIndex].getSocketNumber(), "No such nickname\n", 17, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
}
