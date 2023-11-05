/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:33:54 by israel            #+#    #+#             */
/*   Updated: 2023/11/04 22:05:25 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_capCommand(std::string params, unsigned short clientIndex)
{
    std::string     capList = "CAP * LS :";
    std::string     capReq = "CAP * ACK ";
    std::string     capEnd = "CAP * ACK CAP END";

    std::cout << "params en cap command: |" << params << "|" << std::endl;
    if (params == "LS")
    {
        capList += "\r\n";
        std::cout << "sending: " << capList << std::endl;
        this->_sendMessageToClient(capList, clientIndex);
    }
    else if (params == "REQ :multi-prefix")
    {
        capReq += "\r\n";
        std::cout << "sending: " << capReq << std::endl;
        this->_sendMessageToClient(capReq, clientIndex);
    }
    else if (params == "END")
    {
        capEnd += "\r\n";
        std::cout << "sending: " << capEnd << std::endl;
        this->_sendMessageToClient(capEnd, clientIndex);
    }
}
