/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:34:43 by israel            #+#    #+#             */
/*   Updated: 2023/11/07 21:19:43 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

std::string Reply::f_RPL_WELCOME(std::vector<std::string> &params)
{
    return (std::string(":Welcome to the Internet Relay Network " + params[0]));
}

std::string Reply::f_ERR_NOSUCHNICK(std::vector<std::string> &params)
{
    return (std::string(params[0] + " :No such nick/channel"));
}

std::string Reply::f_ERR_NOSUCHCHANNEL(std::vector<std::string> &params)
{
    return (std::string(params[0] + " :No such channel"));
}

std::string Reply::f_ERR_UNKNOWNCOMMAND(std::vector<std::string> &params)
{
    return (std::string(params[0] + " :Unknown command"));
}

std::string Reply::f_ERR_NOTREGISTERED(std::vector<std::string> &params)
{
    return (std::string(params[0] + " :You have not registered"));
}

std::string Reply::f_ERR_NOPRIVILEGES(std::vector<std::string> &params)
{
    (void)params;
    return (" :Permission Denied- You're not an IRC operator");
}

void    Server::_reply(std::string &message, Client &client, std::vector<std::string> &rep)
{
    int         code;
    std::string nick;

    code = atoi(message.c_str());
    nick = client.getNick();

    client.write_buffer(client, message + " " + nick + Server::_getReply(message, rep));
}

std::string Server::_getReply(std::string &message, std::vector<std::string> &rep)
{
    if (Server::_replies.find(message) == Server::_replies.end())
    {
        std::cout << "Reply not found" << std::endl;
        return ("");
    }
    return (std::string(" " + Server::_replies[message](rep)));
}

void    Server::_initReplies(void)
{
    Server::_replies[Reply::RPL_WELCOME] = Reply::f_RPL_WELCOME;
    Server::_replies[Reply::ERR_NOSUCHNICK] = Reply::f_ERR_NOSUCHNICK;
    Server::_replies[Reply::ERR_NOSUCHCHANNEL] = Reply::f_ERR_NOSUCHCHANNEL;
    Server::_replies[Reply::ERR_UNKNOWNCOMMAND] = Reply::f_ERR_UNKNOWNCOMMAND;
    Server::_replies[Reply::ERR_NOTREGISTERED] = Reply::f_ERR_NOTREGISTERED;
    Server::_replies[Reply::ERR_NOPRIVILEGES] = Reply::f_ERR_NOPRIVILEGES;
}

void
Server::_sendMessageToClient(const std::string &message, unsigned short clientIndex)
{
    int rc;
    std::map<int, Client>::iterator     itClient = _clients.find(clientIndex);

    if (itClient == _clients.end())
        return ;
    else
    {
        int clientSocket = itClient->second.getSocketNumber();
        rc = send(clientSocket, message.c_str(), message.size(), 0);
        if (rc < 0)
        {
            perror("send() failed");
            throw Server::ServerError("send() failed");
        }
    }
}
