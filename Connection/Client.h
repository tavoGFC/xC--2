/*
 * Client.h
 *
 *  Created on: 31 de mar. de 2016
 *      Author: gustavo
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Socket.h"

class Client : private Socket {

public:
	Client ( std::string host, int port);
	Client(){};
	virtual ~Client(){};

	const Client& operator << (const std::string&) const;
	const Client& operator >> (std::string&) const;
};

#endif /* CLIENT_H_ */
