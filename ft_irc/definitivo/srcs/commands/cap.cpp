/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:33:54 by israel            #+#    #+#             */
/*   Updated: 2023/11/17 10:40:02 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_capCommand(std::string params, unsigned short clientIndex)
{
    std::string     capList = "CAP * LS :";
    std::string     capReq = "CAP * ACK ";
    std::string     capEnd = "CAP * ACK CAP END";
	std::map<int, Client>::iterator	it = this->_clients.find(clientIndex);

    if (params == "LS")
		it->second.write_buffer(it->second, capList);
    else if (params == "REQ :multi-prefix")
		it->second.write_buffer(it->second, capReq);
    else if (params == "END")
		it->second.write_buffer(it->second, capEnd);
}
