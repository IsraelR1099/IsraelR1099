/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:21:42 by israel            #+#    #+#             */
/*   Updated: 2023/11/02 13:59:06 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>
# include <map>
# include "Client.hpp"
# include "Ansi.hpp"

class Channel
{
    public:
        Channel(void);
        Channel(const std::string &name);
        Channel(const Channel &src);
        ~Channel(void);


        std::string     getTopic(void) const;
        std::string     getName(void) const;
        void            setName(const std::string &name);
        size_t          getNumClients(void) const;
        void            setTopic(const std::string &topic);
        void            addClient(const Client &client, int nfds, bool isOperator);

    private:
        std::string             _name;
        std::string             _topic;
		std::map<int, Client>	_members;
        std::map<int, Client>   _operators;
};

#endif
