//
// Created by gustavo on 15/04/16.
//

#ifndef XC_2_SOCKET_H
#define XC_2_SOCKET_H


class Socket {
public:
    int leerSocket (int fd, char *Datos, int Longitud);
    int escribirSocket (int fd, char *Datos, int Longitud);
};


#endif //XC_2_SOCKET_H
