/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:21:42 by israel            #+#    #+#             */
/*   Updated: 2023/11/23 13:35:34 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>
# include <map>
# include <sys/socket.h>
# include <sys/types.h>
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
		void			incrementNumClients(void);
        size_t          getNumClients(void) const;
		size_t			getLimit(void);
        void            setTopic(const std::string &topic);
        void            addClient(const Client &client, int nfds, bool isOperator);
        std::map<int, Client>   &getMembers(void);
        std::map<int, Client>   &getOperators(void);
        bool            isClientInChannel(const Client &client) const;

    private:
        std::string             _name;
        std::string             _password;
        std::string             _topic;
		std::map<int, Client>	_members;
        std::map<int, Client>   _operators;
        size_t                  _numClients;
        size_t                  _limit;
		bool					_passwd;
        bool                    _modeI;
        bool                    _modeT;
        bool                    _modeK;
        bool                    _modeO;
        bool                    _modeL;
};

#endif
