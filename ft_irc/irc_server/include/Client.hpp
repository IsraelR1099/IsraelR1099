/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:30 by israel            #+#    #+#             */
/*   Updated: 2023/11/13 13:25:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

# include <iostream>
# include <sys/socket.h>
# include <sys/types.h>
# include "Ansi.hpp"

class Client {
    private:
        int         _socket;
        std::string _nick;
        std::string _user;
        std::string _fullName;
        std::string _host;
        std::string _buffer;
        bool        _isRegistered;
        bool        _isAuthorised;
        bool        _isOperator;

    public:
        Client(void);
        Client(int socket);
        Client(const Client &other);
        Client &operator=(const Client &other);
        ~Client(void);

        // Getters and Setters
        int			        getSocketNumber(void);
        bool        		getIsRegistered(void);
        bool	        	getIsAuthorised(void);
        bool                getIsOperator(void);
        std::string	        getName(void);
        std::string         getUser(void) const;
        const std::string	&getNick(void) const;
        std::string         getFullName(void);
        std::string         getHost(void) const;
        void		        setName(std::string name);
        void                setFullName(std::string fullName);
        void                setHost(const std::string host);
        void        		setIsAuthorised(bool value);
        void	        	setIsRegistered(bool value);
        void                setIsOperator(bool value);
        void		        setNick(std::string nick);
        void                setUser(std::string user);
		std::string			getCustomPrefix(const std::string &code, const std::string channelName) const;
        std::string         getCustomPrefix(const std::string &code);

        // Methods
        void                write_buffer(Client &client, const std::string &message);
		void				send_message(void);
};

#endif
