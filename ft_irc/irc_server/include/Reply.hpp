/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:27:12 by israel            #+#    #+#             */
/*   Updated: 2023/11/06 21:04:17 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
# define REPLY_HPP

# include <string>
# include <vector>

namespace   Reply
{
    // Reply codes
    const std::string   RPL_WELCOME("001");
    const std::string   ERR_NOSUCHNICK("401");
    const std::string   ERR_NOSUCHCHANNEL("403");
    const std::string   ERR_UNKNOWNCOMMAND("421");
    const std::string   ERR_NOTREGISTERED("451");
    const std::string   ERR_NOPRIVILEGES("481");

    // Reply messages
    std::string f_RPL_WELCOME(std::vector<std::string> &params);
    std::string f_ERR_NOSUCHNICK(std::vector<std::string> &params);
    std::string f_ERR_NOSUCHCHANNEL(std::vector<std::string> &params);
    std::string f_ERR_UNKNOWNCOMMAND(std::vector<std::string> &params);
    std::string f_ERR_NOTREGISTERED(std::vector<std::string> &params);
    std::string f_ERR_NOPRIVILEGES(std::vector<std::string> &params);
}
#endif
