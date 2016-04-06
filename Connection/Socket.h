/*
 * Socket.h
 *
 *  Created on: 30 de mar. de 2016
 *      Author: gustavo
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;


class Socket {
public:
	Socket();
	virtual ~Socket();

	//Inicializacion de servidor
	bool create();
	bool bind (const int port);
	bool listen() const;
	bool accept(Socket&) const;

	//Inicializacion del cliente
	bool connect(const std:: string host, const int port);

	//tranmcion de datos
	bool send (const std::string ) const;
	int recv (std::string&) const;

	void setNonBlocking (const bool);

	bool isValid() const {return mSock != -1;}

private:
	int mSock;
	sockaddr_in mAddr;

};

#endif /* SOCKET_H_ */
