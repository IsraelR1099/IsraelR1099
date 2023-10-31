/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:21:42 by israel            #+#    #+#             */
/*   Updated: 2023/10/31 20:26:09 by israel           ###   ########.fr       */
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
        Channel(const std::string &topic);
        Channel(const Channel &src);
        ~Channel(void);


        std::string     getTopic(void) const;
        size_t          getNumClients(void) const;
        void            setTopic(const std::string &topic);
        void            addClientTo(int nfds, std::string &chan, Client client);

    private:
		std::map<int, Client>	_members;
        std::string             _topic;
        std::map<int, Client>   _operators;
};

#endif
