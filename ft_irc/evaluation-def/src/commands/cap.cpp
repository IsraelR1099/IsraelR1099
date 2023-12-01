/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:33:54 by israel            #+#    #+#             */
/*   Updated: 2023/12/01 09:23:31 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_capCommand(std::string params, unsigned short clientIndex)
{
    std::string     capList = "CAP * LS :";
    std::string     capReq = "CAP * ACK ";
    std::string     capEnd = "CAP * ACK CAP END";

    if (params == "LS")
    {
        capList += "\r\n";
        this->_sendMessageToClient(capList, clientIndex);
    }
    else if (params == "REQ :multi-prefix")
    {
        capReq += "\r\n";
        this->_sendMessageToClient(capReq, clientIndex);
    }
    else if (params == "END")
    {
        capEnd += "\r\n";
        this->_sendMessageToClient(capEnd, clientIndex);
    }
}
