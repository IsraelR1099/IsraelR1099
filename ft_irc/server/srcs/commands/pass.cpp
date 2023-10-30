/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:48:48 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/27 11:14:42 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    else if (params == m_password)
        client.setIsAuthorised(true);
    else
    {
        rc = send(client.getSocketNumber(), "Wrong password\n", 15, 0);
        if (rc < 0)
            throw Server::ServerError("send() failed");
    }
}
