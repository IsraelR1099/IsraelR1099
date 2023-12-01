/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:27:12 by israel            #+#    #+#             */
/*   Updated: 2023/11/29 11:22:32 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
# define REPLY_HPP

# include <string>
# include <vector>

namespace   Reply
{
    // Reply codes
    static const std::string    RPL_WELCOME("001");
    static const std::string    RPL_CHANNELMODEIS("324");
    static const std::string    RPL_NOTOPIC("331");
    static const std::string    RPL_TOPIC("332");
    static const std::string    RPL_TOPICWHOTIME("333");
    static const std::string    RPL_INVITING("341");
    static const std::string    RPL_NAMREPLY("353");
    static const std::string    RPL_ENDOFNAMES("366");
    

    static const std::string    ERR_NOSUCHNICK("401");
    static const std::string    ERR_NOSUCHCHANNEL("403");
    static const std::string    ERR_CANNOTSENDTOCHAN("404");
    static const std::string    ERR_NORECIPIENT("411");
    static const std::string    ERR_NOTEXTTOSEND("412");
    static const std::string    ERR_UNKNOWNCOMMAND("421");
    
    static const std::string    ERR_NONICKNAMEGIVEN("431");
    static const std::string    ERR_ERRONEOUSNICKNAME("432");
    static const std::string    ERR_NICKNAMEINUSE("433");
    static const std::string    ERR_USERNOTINCHANNEL("441");
    static const std::string    ERR_NOTONCHANNEL("442");
    static const std::string    ERR_USERONCHANNEL("443");
    static const std::string    ERR_NOTREGISTERED("451");
    
    static const std::string    ERR_NEEDMOREPARAMS("461");
    static const std::string    ERR_ALREADYREGISTERED("462");
    static const std::string    ERR_PASSWDMISMATCH("464");
    
    static const std::string    ERR_CHANNELISFULL("471");
    static const std::string    ERR_UNKNOWNMODE("472");
    static const std::string    ERR_INVITEONLYCHAN("473");
    static const std::string    ERR_BADCHANNELKEY("475");
    
    static const std::string    ERR_NOPRIVILEGES("481");
    static const std::string    ERR_CHANOPRIVSNEEDED("482");

    static const std::string    ERR_INVALIDMODEPARAM("696");

    // Reply messages
    const std::string   f_RPL_WELCOME(const std::vector<std::string> &params);
    const std::string   f_RPL_CHANNELMODEIS(const std::vector<std::string> &params);
    const std::string   f_RPL_NOTOPIC(const std::vector<std::string> &params);
    const std::string   f_RPL_TOPIC(const std::vector<std::string> &params);
    const std::string   f_RPL_TOPICWHOTIME(const std::vector<std::string> &params);
    const std::string   f_RPL_INVITING(const std::vector<std::string> &params);
    const std::string   f_RPL_NAMREPLY(const std::vector<std::string> &params);
    const std::string   f_RPL_ENDOFNAMES(const std::vector<std::string> &params);

    const std::string   f_ERR_NOSUCHNICK(const std::vector<std::string> &params);
    const std::string   f_ERR_NOSUCHCHANNEL(const std::vector<std::string> &params);
    const std::string   f_ERR_NORECIPIENT(const std::vector<std::string> &params);
    const std::string   f_ERR_NOTEXTTOSEND(const std::vector<std::string> &params);

    const std::string   f_ERR_UNKNOWNCOMMAND(const std::vector<std::string> &params);
    const std::string   f_ERR_NONICKNAMEGIVEN(const std::vector<std::string> &params);
    const std::string   f_ERR_ERRONEOUSNICKNAME(const std::vector<std::string> &params);
    const std::string   f_ERR_NICKNAMEINUSE(const std::vector<std::string> &params);
    const std::string   f_ERR_USERNOTINCHANNEL(const std::vector<std::string> &params);
    const std::string   f_ERR_NOTONCHANNEL(const std::vector<std::string> &params);
    const std::string   f_ERR_USERONCHANNEL(const std::vector<std::string> &params);
    const std::string   f_ERR_NOTREGISTERED(const std::vector<std::string> &params);
    const std::string   f_ERR_NEEDMOREPARAMS(const std::vector<std::string> &params);
    const std::string   f_ERR_ALREADYREGISTERED(const std::vector<std::string> &params);
    const std::string   f_ERR_PASSWDMISMATCH(const std::vector<std::string> &params);
    const std::string   f_ERR_CHANNELISFULL(const std::vector<std::string> &params);
    const std::string   f_ERR_UNKNOWNMODE(const std::vector<std::string> &params);
    const std::string   f_ERR_INVITEONLYCHAN(const std::vector<std::string> &params);
    const std::string   f_ERR_BADCHANNELKEY(const std::vector<std::string> &params);


    const std::string   f_ERR_NOPRIVILEGES(const std::vector<std::string> &params);
    const std::string   f_ERR_CHANOPRIVSNEEDED(const std::vector<std::string> &params);
    
    const std::string   f_ERR_INVALIDMODEPARAM(const std::vector<std::string> &params);
}

#endif
