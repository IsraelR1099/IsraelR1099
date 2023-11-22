/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:59:50 by israel            #+#    #+#             */
/*   Updated: 2023/11/22 13:33:32 by irifarac         ###   ########.fr       */
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
		std::string	params(tokens[0]);
		std::string prefix = _clients[clientIndex].getCustomPrefix("403", params);
		std::cout << "prefix: " << prefix << std::endl;
		Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
		return (-1);
    }
	else if (tokens[2][0] != ':')
	{
        std::cout << ANSI::red <<
        "ERR_NEEDMOREPARAMS :Not enough parameters" <<
        ANSI::reset << std::endl;
        std::string prefix = _clients[clientIndex].getCustomPrefix("461", "KICK");
        Server::_message(Reply::ERR_NEEDMOREPARAMS, _clients[clientIndex], std::vector<std::string>(1, prefix));
        return (-1);
    }
	for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++)
		std::cout << "en kick token: " << *it << std::endl;
	return (0);
}

void    Server::_kickCommand(std::string params, unsigned short clientIndex)
{
    std::istringstream				iss(params);
    std::vector<std::string>		tokens;
    std::string						token;
	std::map<int, Client>::iterator	itClient;

    while (std::getline(iss, token, ' '))
        tokens.push_back(token);
    if (_errorKickCommand(tokens, clientIndex) == -1)
        return ;
	//Check if operator exists in clients map of Server
	itClient = this->_clients.find(clientIndex);
	if (itClient != this->_clients.end())
	{
		std::cout << "client operator en kick: " << itClient->second.getNick() << std::endl;
		//Check if the channel exists in map of Server
		Channel	*tmpChannel = this->_getChannelByName(tokens[0]);

		if (tmpChannel)
		{
			std::map<int, Client>	members = tmpChannel->getMembers();

			std::cout << "size of members: " <<  members.size() << std::endl;
			for (std::map<int, Client>::iterator itMember = members.begin(); itMember != members.end(); itMember++)
				std::cout << "nick is: " << itMember->second.getSocketNumber() << std::endl;
			//Check if this client, who is typing KICK, is an operator
		/*	std::map<int, Client>::iterator	itClientIn = tmpChannel->_operators.find(clientIndex);
			if (itClientIn != it->Channel->second->_operators.end())
			{
				std::cout << "todo bien\n";
				//this->_receiveClient(socketClientRemove);
			}
			else
			{
				std::cout << ANSI::red <<
					"ERR_CHANOPRIVSNEEDED :You're not channel operator" <<
					ANSI::reset << std::endl;
				std::string	prefix = _clients[clientIndex].getCustomPrefix("482", params);
				Server::_message(Reply::ERR_CHANOPRIVSNEEDED, _clients[clientIndex],
						std::vector<std::string>(1, prefix));
			}*/
			std::cout << "channel name is: " << tmpChannel->getName() << std::endl;
		}
		else
		{
			std::cout << ANSI::red <<
				"ERR_NOSUCHCHANNEL :No such channel" <<
				ANSI::reset << std::endl;
			std::string	params(tokens[0]);
			std::string prefix = _clients[clientIndex].getCustomPrefix("403", params);
			std::cout << "prefix: " << prefix << std::endl;
			Server::_message(Reply::ERR_NOSUCHCHANNEL, _clients[clientIndex], std::vector<std::string>(1, prefix));
		}
	}
}
