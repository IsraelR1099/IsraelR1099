/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:52:16 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/01 13:11:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void	Server::_passCommand(std::string params, unsigned short clientIndex)
{
    int rc;

    if (_clients[clientIndex].getIsAuthorised())
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "You are already authorised\n", 27, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
    else if (params == m_password)
        _clients[clientIndex].setIsAuthorised(true);
    else
    {
        rc = send(_clients[clientIndex].getSocketNumber(), "Wrong password\n", 15, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
}
