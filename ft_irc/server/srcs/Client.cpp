/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:48:38 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/30 12:31:42 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Client.hpp"

Client::Client() {
    _socket = 0;
    _isRegistered = false;
    _isAuthorised = false;
}

Client::Client(int socket)
{
    _socket = socket;
    _isRegistered = false;
    _isAuthorised = false;
}

// copy operator
Client::Client(const Client &other)
{
    _socket = other._socket;
}

// assignment operator
Client &Client::operator=(const Client &other)
{
     if (this != &other) {
    _socket = other._socket;
     }
    return *this;
}

Client::~Client()
{
}

int Client::getSocketNumber() {
    return _socket;
}

void Client::setIsRegistered(bool value) {
    _isRegistered = value;
}

bool Client::getIsRegistered() {
    return _isRegistered;
}
void Client::setIsAuthorised(bool value) {
    _isAuthorised = value;
}
bool Client::getIsAuthorised() {
    return _isAuthorised;
}

void Client::setName(std::string name) {
    _name = name;
}

std::string Client::getName() {
    return _name;
}

void Client::setNick(std::string nick) {
    _nick = nick;
}

const std::string &Client::getNick() const
{
    return _nick;
}
