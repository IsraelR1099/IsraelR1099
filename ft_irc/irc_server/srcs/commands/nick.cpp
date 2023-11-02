/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:57:38 by israel            #+#    #+#             */
/*   Updated: 2023/10/31 18:35:03 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void	Server::_nickCommand(std::string params, unsigned short clientIndex)
{
 /*   std::vector<std::string>    nicknames;
    int rc;

    if (!_clients[clientIndex].getIsAuthorised())
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "You must be authorised to use this command\n", 44, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
        return ;
    }

    nicknames = _getAllClientNicknames(_clients);
    if (std::find(nicknames.begin(), nicknames.end(), params) != nicknames.end())
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "Nickname already taken\n", 23, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }

    // **  CHECK IF NICKNAME IS TOO LONG ** //
    if (params.length() > 9)
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "Nickname too long\n", 19, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }

    // **  CHECK IF BAD CHARS ** //
    std::regex validCharsRegex("[a-zA-Z0-9\\[\\]\\\\`_\\^\\{\\|\\}]+");
    if (std::regex_match(params, validCharsRegex) == false || (params[0] >= '0' && params[0] <= '9'))
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "Nickname contains bad characters\n", 33, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }

    if (_clients[clientIndex].getIsAuthorised())
        _clients[clientIndex].setNick(params);
    else
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "You must be authorised to use this command\n", 44, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
    if (_clients[clientIndex].getUser().length() > 0)
        _clients[clientIndex].setIsRegistered(true);*/
    std::cout << "NICK" << std::endl;
    std::cout << params << std::endl;
    std::cout << clientIndex << std::endl;
}
