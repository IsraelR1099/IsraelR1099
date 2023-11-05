/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:30 by israel            #+#    #+#             */
/*   Updated: 2023/11/03 17:48:27 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client {
    private:
        int         _socket;
        std::string _nick;
        std::string _user;
        std::string _fullName;
        bool        _isRegistered;
        bool        _isAuthorised;
        bool        _isOperator;

    public:
        Client(void);
        Client(int socket);
        Client(const Client &other);
        Client &operator=(const Client &other);
        ~Client(void);

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
};

#endif
