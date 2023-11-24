/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:59:50 by israel            #+#    #+#             */
/*   Updated: 2023/11/24 13:03:56 by irifarac         ###   ########.fr       */
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

int clientIsInChannel(Channel *channel, std::string &client)
{
    std::map<int, Client>           tmpMap = channel->getMembers();
    std::map<int, Client>::iterator itClient = tmpMap.begin();

    while (itClient != tmpMap.end())
    {
        if (itClient->second.getNick() == client)
            return (itClient->first);
        itClient++;
    }
    return (-1);
}

void    Server::_kickCommand(std::string params, unsigned short clientIndex)
{
    std::istringstream				iss(params);
    std::vector<std::string>		tokens;
    std::string						token;
	std::map<int, Client>::iterator	itClient;
    int                             socketClientRemove;

    while (std::getline(iss, token, ' '))
        tokens.push_back(token);
    if (_errorKickCommand(tokens, clientIndex) == -1)
    {
        return ;
    }
	//Check if operator exists in clients map of Server
	itClient = this->_clients.find(clientIndex);
    if (itClient != this->_clients.end())
	{
		//Check if the channel exists in map of Server
		Channel	*tmpChannel = this->_getChannelByName(tokens[0]);
		std::map<int, Client>	tmpChannel2 = tmpChannel->getMembers();
		std::map<int, Client>::iterator clients = tmpChannel2.begin();

		while (clients != tmpChannel2.end())
		{
			std::cout << "Clients before deleting: " << clients->second.getNick() << std::endl;
			clients++;
		}

		if (tmpChannel)
		{
			//Check if this client, who is typing KICK, is an operator
            std::map<int, Client>   tmpMap = tmpChannel->getOperators();
            std::map<int, Client>::iterator itClientIn = tmpMap.find(clientIndex);
			if (itClientIn != tmpMap.end())
			{
                //Check if the client to kick is in the channel
                socketClientRemove = clientIsInChannel(tmpChannel, tokens[1]);
                if (socketClientRemove > 0)
                {
                    std::cout << "client a kickear: " << tokens[1] << std::endl;
					std::vector<std::string>	messageKick;

					std::string message = ":" + itClient->second.getNick()
                        + " KICK " + tokens[0] + " " + tokens[1] + " "
                        + ":" + tokens[3];
                    std::map<int, Client>::iterator itClientRemove = this->_clients.find(socketClientRemove);
                    if (itClientRemove != this->_clients.end())
                    {
						itClientRemove->second.write_buffer(itClientRemove->second, message);
						tmpChannel->_removeClientFromChannel(socketClientRemove);
						this->_channels[_getChannelKey(tmpChannel->getName())] = *tmpChannel;
                    }
                }
                else
                {
                    std::cout << ANSI::red <<
                    "ERR_USERNOTINCHANNEL :They aren't on that channel" <<
                    ANSI::reset << std::endl;
                    std::vector<std::string> options;
                    options.push_back(tokens[1]);
                    options.push_back(tokens[0]);
                    std::string	prefix = _clients[clientIndex].getCustomPrefix("441", options);
                    Server::_message(Reply::ERR_USERNOTINCHANNEL, _clients[clientIndex],
                            std::vector<std::string>(1, prefix));
                }
			}
			else
			{
				std::cout << ANSI::red <<
					"ERR_CHANOPRIVSNEEDED :You're not channel operator" <<
					ANSI::reset << std::endl;
				std::string	prefix = _clients[clientIndex].getCustomPrefix("482", params);
				Server::_message(Reply::ERR_CHANOPRIVSNEEDED, _clients[clientIndex],
						std::vector<std::string>(1, prefix));
			}
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
