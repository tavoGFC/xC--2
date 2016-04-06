/*
 * Socket.cpp
 *
 *  Created on: 30 de mar. de 2016
 *      Author: gustavo
 */

#include "Socket.h"
#include "string.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>

using namespace std;


Socket::Socket() : mSock(-1){
	memset(&mAddr, 0, sizeof(mAddr));
}

Socket::~Socket(){
	if(isValid() ){
		::close(mSock);
	}
}

//funcion crear
bool Socket::create(){
	mSock = socket(AF_INET, SOCK_STREAM, 0);

	if(! isValid()){
		return false;
	}

	//tiempo de espera
	int on = 1;
	if (setsockopt (mSock, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) == -1){
		return false;
	}
	return true;
}

//funcion buscar
bool Socket::bind( const int port){
	if (! isValid()){
		return false;
	}

	mAddr.sin_family = AF_INET;
	mAddr.sin_addr.s_addr = INADDR_ANY;
	mAddr.sin_port = htons(port);

	int bind_return = ::bind(mSock, (struct sockaddr *)&mAddr, sizeof(mAddr) );

	if (bind_return == -1){
		return false;
	}
	return true;

}

//funcion para ecuchar puerto
bool Socket::listen() const{
	if(! isValid()) {
		return false;
	}

	int listen_return = ::listen(mSock, MAXCONNECTIONS);

	if(listen_return == -1){
		return false;
	}

	return true;

}

//funcion aceptar, la comunicacion
bool Socket::accept( Socket& new_socket) const{
	int addr_length = sizeof (mAddr);
	new_socket.mSock = ::accept (mSock, (sockaddr *)&mAddr, (socklen_t *)&addr_length);

	if(new_socket.mSock <= 0){
		return false;
	}
	else{ return true;}

}

//funcion para enviar
bool Socket::send( const std::string s) const{
	int status =::send(mSock, s.c_str(), s.size(), MSG_NOSIGNAL);
	if(status == -1){
		return false;
	}
	else{ return true;}

}

int Socket::recv( std::string& s) const{
	char buf [MAXRECV + 1];

	s = "";

	memset(buf, 0, MAXRECV + 1);

	int status = ::recv (mSock, buf, MAXRECV, 0);

	if(status == -1){
		cout << "status == -1 errno == " << errno << "in Socket::recv\n";
		return 0;
	}
	else if(status == 0){
		return 0;
	}
	else {
		s = buf;
		return status;
	}

}


bool Socket::connect(const std::string host, const int port){

	if( ! isValid()) {
		return false;
	}

	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons (port);

	int status = inet_pton (AF_INET, host.c_str(), &mAddr.sin_addr);

	if (errno == EAFNOSUPPORT) {
		return false;
	}

	status = ::connect (mSock, (sockaddr *)&mAddr, sizeof (mAddr));

	if (status == 0){
		return true;
	}
	else {return false;}

}

//funcion setNonBlocking
void Socket::setNonBlocking(const bool b){
	int opt;

	opt = fcntl(mSock, F_GETFL);

	if(opt < 0){
		return;
	}

	if (b){
		opt = (opt | O_NONBLOCK);
	}
	else{
		opt = (opt & ~O_NONBLOCK);
	}

	fcntl(mSock, F_SETFD, opt);
}









