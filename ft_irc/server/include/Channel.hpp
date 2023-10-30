/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:21:42 by israel            #+#    #+#             */
/*   Updated: 2023/10/30 13:26:17 by irifarac         ###   ########.fr       */
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
        Channel(std::string topic);
        Channel(const Channel &src);
        ~Channel(void);


        std::string     getTopic(void) const;
        size_t          getNumClients(void) const;
        void            setTopic(std::string &topic);
        void            addClientTo(int nfds, std::string &chan, Client client);

    private:
		std::map<int, Client>	_members;
		std::string				_topic;
};

#endif
