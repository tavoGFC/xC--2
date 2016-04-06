/*
 * Client.cpp
 *
 *  Created on: 31 de mar. de 2016
 *      Author: gustavo
 */

#include "Client.h"
#include "SocketException.h"


Client::Client (std::string host, int port){
	if(! Socket::create()){
		throw SocketException("no se ha podido crear el socket de client");
	}

	if(! Socket::connect(host, port)){
		throw SocketException("no se ha podido conectar con el puerto");
	}

}


const Client& Client::operator <<(const std::string& s) const{
	if(! Socket::send(s)){
		throw SocketException("no se ha escrito el socket");
	}
	return *this;
}

const Client& Client::operator >>(std::string& s) const{
	if(! Socket::recv(s)){
		throw SocketException("no se ha leido desde el socket");
	}
	return *this;
}
