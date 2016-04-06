/*
 * Server.cpp
 *
 *  Created on: 30 de mar. de 2016
 *      Author: gustavo
 */

#include "Server.h"
#include "SocketException.h"



Server::Server(int port) {
	if (! Socket::create() ){
		throw SocketException ("no se ha creado el server socket");
	}

	if (! Socket::bind (port)){
		throw SocketException ("no se puede enlazar puerto");
	}

	if (! Socket::listen()){
		throw SocketException ("no se puede escuchar el puerto");
	}

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

const Server& Server::operator <<(const std::string& s) const{
	if (! Socket::send (s)){
		throw SocketException ("No se puede escribir el socket");
	}
	return *this;
}

const Server& Server::operator >>(std ::string& s) const{
	if(! Socket::recv (s)){
		throw SocketException ("no se ha podido leer desde el socket");
	}
	return *this;
}

void Server::accept(Server& sock){
	if(! Socket::accept (sock)){
		throw SocketException ("no se ha podido aceptar el socket");
	}
}

