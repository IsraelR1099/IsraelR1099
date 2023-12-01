/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:42:35 by israel            #+#    #+#             */
/*   Updated: 2023/11/06 11:26:13 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_pingCommand(std::string params, unsigned short clientIndex)
{
    std::string     response;

    response = "PONG " + params + "\r\n";
    this->_sendMessageToClient(response, clientIndex);
}
