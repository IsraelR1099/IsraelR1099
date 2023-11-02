/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:34:43 by israel            #+#    #+#             */
/*   Updated: 2023/11/02 20:25:35 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

void    Server::_sendMessageToClient(const std::string &message, unsigned short clientIndex)
{
    int rc;
    std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);

    if (itClient == _clients.end())
        return ;
    else
    {
        int clientSocket = itClient->second.getSocketNumber();
        rc = send(clientSocket, message.c_str(), message.size(), 0);
        if (rc < 0)
        {
            perror("send() failed");
            throw Server::ServerError("send() failed");
        }
    }
}
