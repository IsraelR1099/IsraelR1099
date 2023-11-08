/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:30 by israel            #+#    #+#             */
/*   Updated: 2023/11/08 11:07:49 by irifarac         ###   ########.fr       */
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
        std::string         getUser(void);
        const std::string	&getNick(void) const;
        std::string         getFullName(void);
        void		        setName(std::string name);
        void                setFullName(std::string fullName);
        void        		setIsAuthorised(bool value);
        void	        	setIsRegistered(bool value);
        void                setIsOperator(bool value);
        void		        setNick(std::string nick);
        void                setUser(std::string user);
		std::string			getCustomPrefix(void) const;

        // Methods
        void                write_buffer(Client &client, const std::string &message);
		void				send_message(void) const;
};

#endif
