/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:27:12 by israel            #+#    #+#             */
/*   Updated: 2023/11/22 12:52:37 by irifarac         ###   ########.fr       */
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
    static const std::string    ERR_NOSUCHNICK("401");
    static const std::string    ERR_NOSUCHCHANNEL("403");
    static const std::string    ERR_UNKNOWNCOMMAND("421");
    static const std::string    RPL_TOPIC("332");
    static const std::string    ERR_NOTREGISTERED("451");
    static const std::string    ERR_NEEDMOREPARAMS("461");
    static const std::string    ERR_CHANNELISFULL("471");
    static const std::string    ERR_NOPRIVILEGES("481");
	 static const std::string	ERR_CHANOPRIVSNEEDED("482");

    // Reply messages
    const std::string   f_RPL_WELCOME(const std::vector<std::string> &params);
    const std::string   f_ERR_NOSUCHNICK(const std::vector<std::string> &params);
    const std::string   f_ERR_NOSUCHCHANNEL(const std::vector<std::string> &params);
    const std::string   f_ERR_UNKNOWNCOMMAND(const std::vector<std::string> &params);
    const std::string   f_RPL_TOPIC(const std::vector<std::string> &params);
    const std::string   f_ERR_NOTREGISTERED(const std::vector<std::string> &params);
    const std::string   f_ERR_NEEDMOREPARAMS(const std::vector<std::string> &params);
    const std::string   f_ERR_CHANNELISFULL(const std::vector<std::string> &params);
    const std::string   f_ERR_NOPRIVILEGES(const std::vector<std::string> &params);
	const std::string	f_ERR_CHANOPRIVSNEEDED(const std::vector<std::string> &params);
}
#endif
