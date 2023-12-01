/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:21:42 by israel            #+#    #+#             */
/*   Updated: 2023/11/29 13:20:56 by dbekic           ###   ########.fr       */
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


        std::string             getTopic(void) const;
        std::string             getName(void) const;
        void                    setName(const std::string &name);
		void			        incrementNumClients(void);
        size_t                  getNumClients(void) const;
        void                    setTopic(const std::string &topic);
        void                    addClient(const Client &client, int nfds, bool isOperator);
        void                    removeChannelClient(const Client &client);
        bool                    isClientInvited(const Client &client) const;
        std::map<int, Client>   &getMembers(void);
        std::map<int, Client>   &getOperators(void);
        std::map<int, Client>   &getInvitees(void);
        bool                    isClientInChannel(const Client &client) const;
        bool                    isClientInChannel(unsigned short clientIndex);
        std::string             getTopicChanger(void);
        void                    setTopicChanger(std::string);
        time_t                  getTopicChangeTime(void);
        void                    setTopicChangeTime(time_t);
        

		size_t			        getLimit(void);
        void                    setLimit(size_t limit);
        bool                    getModeT();
        void                    setModeT(bool boolean);
        bool                    getModeI();
        void                    setModeI(bool boolean);
        bool                    getModeL();
        void                    setModeL(bool boolean);
        std::string             getKey();
        void                    setKey(std::string key);

    private:
        std::string             _name;
        std::string             _password;
        std::string             _topic;
        std::string             _topicChanger;
        time_t             _topicChangeTime;
		std::map<int, Client>	_members;
        std::map<int, Client>   _operators;
        std::map<int, Client>   _invitees;
        size_t                  _numClients;
        size_t                  _limit;
		std::string				_key;
        bool                    _modeI;
        bool                    _modeT;
        bool                    _modeK;
        bool                    _modeO;
        bool                    _modeL;
};

#endif
