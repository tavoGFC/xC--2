/*
 * Server.h
 *
 *  Created on: 30 de mar. de 2016
 *      Author: gustavo
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "Socket.h"

class Server  : private Socket{

public:
	Server (int port);
	Server (){};
	virtual ~Server();

	const Server& operator << (const std::string&) const;
	const Server& operator >> (std::string&) const;

	void accept (Server&);

};

#endif /* SERVER_H_ */
