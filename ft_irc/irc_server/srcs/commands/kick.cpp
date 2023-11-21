/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:59:50 by israel            #+#    #+#             */
/*   Updated: 2023/11/21 20:42:46 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

int  Server::_errorKickCommand(std::vector<std::string> &tokens, unsigned short clientIndex)
{
    std::cout << "canal es: " << tokens[0] << std::endl;
    std::cout << "character: " << tokens[0][0] << std::endl;
    if (tokens.size() < 4)
    {
        std::cout << ANSI::red <<
        "ERR_NEEDMOREPARAMS :Not enough parameters" <<
        ANSI::reset << std::endl;
        std::string prefix = _clients[clientIndex].getCustomPrefix("461", "KICK");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return (-1);
    }
    else if (tokens[0][0] != '#')
    {
        std::cout << ANSI::red <<
            "ERR_NOSUCHCHANNEL :No such channel" <<
            ANSI::reset << std::endl;
            std::string prefix = _clients[clientIndex].getCustomPrefix("403", params);
            std::cout << "prefix: " << prefix << std::endl;
            Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
            return (-1);
    }
        for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++)
        std::cout << "en kick token: " << *it << std::endl;


}

void    Server::_kickCommand(std::string params, unsigned short clientIndex)
{
    std::istringstream          iss(params);
    std::vector<std::string>    tokens;
    std::string                 token;

    while (std::getline(iss, token, ' '))
        tokens.push_back(token);
    if (_errorKickCommand(tokens, clientIndex) == -1)
        return ;
   }
