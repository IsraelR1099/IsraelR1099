/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:52:54 by israel            #+#    #+#             */
/*   Updated: 2023/11/05 20:38:11 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_modeCommand(std::string params, unsigned short clientIndex)
{

    std::cout << "MODE" << std::endl;
    std::cout << params << std::endl;
    std::cout << clientIndex << std::endl;
    if (!params.empty() && params[0] == '#')
        std::cout << "MODE CHANNEL" << std::endl;
    else
    {
        std::cout << "sending Unknown MODE flag" << std::endl;
        _sendMessageToClient(":Unknown MODE flag\r\n", clientIndex);
    }
}
