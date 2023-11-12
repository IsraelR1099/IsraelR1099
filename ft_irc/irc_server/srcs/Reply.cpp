/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:34:43 by israel            #+#    #+#             */
/*   Updated: 2023/11/12 14:29:33 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

const std::string Reply::f_RPL_WELCOME(const std::vector<std::string> &params)
{
    return (std::string(":Welcome to the Internet Relay Network " + params[0]));
}

const std::string Reply::f_ERR_NOSUCHNICK(const std::vector<std::string> &params)
{
    return (std::string(params[0] + " :No such nick/channel"));
}

const std::string Reply::f_ERR_NOSUCHCHANNEL(const std::vector<std::string> &params)
{
    return (std::string(params[0] + " :No such channel"));
}

const std::string Reply::f_ERR_UNKNOWNCOMMAND(const std::vector<std::string> &params)
{
    return (std::string(params[0] + " :Unknown command"));
}

const std::string   Reply::f_RPL_TOPIC(const std::vector<std::string> &params)
{
    return (std::string(params[0] + " :" + params[1]));
}

const std::string Reply::f_ERR_NOTREGISTERED(const std::vector<std::string> &params)
{
    return (std::string(params[0] + " :You have not registered"));
}

const std::string   Reply::f_ERR_NEEDMOREPARAMS(const std::vector<std::string> &params)
{
    return (std::string(params[0] + " :Not enough parameters"));
}

const std::string   Reply::f_ERR_CHANNELISFULL(const std::vector<std::string> &params)
{
    return (std::string(params[0] + " :Cannot join channel (+l)"));
}

const std::string Reply::f_ERR_NOPRIVILEGES(const std::vector<std::string> &params)
{
    (void)params;
    return (" :Permission Denied- You're not an IRC operator");
}

void
Server::_message(const std::string &message, Client &client, const std::vector<std::string> &rep)
{
    int         code;
    std::string nick;

    code = atoi(message.c_str());
    nick = client.getNick();

    (void)code;
    client.write_buffer(client, message + " " + nick + Server::_getReply(message, rep));
}

std::string Server::_getReply(const std::string &message, const std::vector<std::string> &rep)
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
    Server::_replies[Reply::RPL_TOPIC] = Reply::f_RPL_TOPIC;
    Server::_replies[Reply::ERR_NOTREGISTERED] = Reply::f_ERR_NOTREGISTERED;
    Server::_replies[Reply::ERR_NEEDMOREPARAMS] = Reply::f_ERR_NEEDMOREPARAMS;
    Server::_replies[Reply::ERR_CHANNELISFULL] = Reply::f_ERR_CHANNELISFULL;
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
