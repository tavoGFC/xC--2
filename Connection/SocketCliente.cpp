//
// Created by gustavo on 15/04/16.
//

#include "SocketCliente.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>


/*
 * Conecta con un servidor Unix, en la misma maquina.
 * devuelve descriptor de socket, y -1 si hay algun error.
 */
int SocketCliente::abrirConexionUNIX(char *Servicio) {
    struct sockaddr_un direccion;
    int descriptor;

    strcpy(direccion.sun_path, Servicio);
    direccion.sun_family = AF_UNIX;

    descriptor = socket(AF_UNIX, SOCK_STREAM, 0);
    if (descriptor == -1){
        return -1;
    }

    /*
     * Retorna 0 si ocurre conexion.
     * retorna -1 si hay error.
     */
    if (connect(descriptor,(struct sockaddr *)&direccion,
                strlen(direccion.sun_path) + sizeof(direccion.sun_family)) == -1){
        return -1;
    }
    else{
        return descriptor;
    }
}


/*
 * Conecta con un servidor remoto a traves de socket INET
 */
int SocketCliente::abrirConexionINET(char *host, char *Servicio) {
    struct sockaddr_in direccion;
    struct servent *puerto;
    struct hostent *hostC;
    int descriptor;

    puerto = getservbyname(host, "tcp");
    if (puerto == NULL){
        return -1;
    }

    hostC = gethostbyname(host);
    if (host == NULL){
        return -1;
    }

    direccion.sin_family = AF_INET;
    direccion.sin_addr.s_addr = ((struct in_addr *)(hostC->h_addr))->s_addr;
    direccion.sin_port = puerto->s_port;

    descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (descriptor == -1){
        return -1;
    }
    if (connect(descriptor, (struct sockaddr *)&direccion, sizeof(direccion)) == -1){
        return -1;
    }

    return descriptor;

}