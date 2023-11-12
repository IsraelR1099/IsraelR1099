/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:42:35 by israel            #+#    #+#             */
/*   Updated: 2023/11/09 22:00:56 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

void    Server::_pingCommand(std::string params, unsigned short clientIndex)
{
    std::string                     response;
    std::map<int, Client>::iterator it = this->_clients.find(clientIndex);

    if (params.empty())
    {
        if (it != this->_clients.end())
        {
            std::string prefix = it->second.getCustomPrefix("461", "PING");

            Server::_message(Reply::ERR_NEEDMOREPARAMS, it->second, std::vector<std::string>(1, prefix));
            return ;
        }
    }
    response = "PONG :" + params;
    it->second.write_buffer(it->second, response);
}
