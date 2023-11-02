/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:33:54 by israel            #+#    #+#             */
/*   Updated: 2023/11/02 21:39:21 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_capCommand(std::string params, unsigned short clientIndex)
{
    std::string     capList = "CAP LS :";

    capList += "multi-prefix sasl";
    capList += "\r\n";
    this->_sendMessageToClient(capList, clientIndex);
    (void)params;
}
