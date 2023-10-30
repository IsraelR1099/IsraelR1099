/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:21:42 by israel            #+#    #+#             */
/*   Updated: 2023/10/30 10:45:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <set>
# include <string>
# include "Client.hpp"

class Channel
{
    public:
        Channel(void);
        Channel(std::string topic);
        Channel(const Channel &src);
        ~Channel(void);

        std::string     getTopic(void) const;
        void            setTopic(std::string &topic);
        void            addClient(Client client);
        size_t          getNumClients(void) const;

		bool			operator<(const Client &other) const;

    private:
		std::set<Client>	_clients;
		std::string			_topic;
};

#endif
