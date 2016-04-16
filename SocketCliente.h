//
// Created by gustavo on 15/04/16.
//

#ifndef XC_2_SOCKETCLIENTE_H
#define XC_2_SOCKETCLIENTE_H


class SocketCliente {

public:
    int abrirConexionUNIX (char *Servicio);
    int abrirConexionINET (char *host, char *Servicio);
};


#endif //XC_2_SOCKETCLIENTE_H
