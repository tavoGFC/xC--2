//
// Created by gustavo on 15/04/16.
//

#ifndef XC_2_SOCKETSERVIDOR_H
#define XC_2_SOCKETSERVIDOR_H


class SocketServidor {
public:
    int abreSocketINET (char *Servicio);
    int abreSocketUNIX (char *Servicio);
    int aceptarConexionCliente (int descriptor);
};


#endif //XC_2_SOCKETSERVIDOR_H
