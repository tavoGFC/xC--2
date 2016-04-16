//
// Created by gustavo on 15/04/16.
//

#include "Socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

/*
 * Lee los datos del socket.
 * Retorna el numero de bytes leidos
 * 0 si se cierra fichero
 * -1 si hay algun error
 *
 */

int Socket::leerSocket(int fd, char *Datos, int Longitud) {
    int leido = 0;
    int aux = 0;

    /*
     * comprobar de que los parametros de entrada son correctos
     */
    if ((fd == -1 ) || (Datos == NULL) || (Longitud < 1)){
        return -1;
    }

    //mientras no se lean todos los datos solicitados
    while(leido < Longitud){
        aux = read(fd, Datos + leido, Longitud - leido);
        if (aux > 0){
            //cuando lee los datos, incrementamos la variable
            //que contiene los datos leidos hasta el momento
            leido = leido + aux;
        }
        else{
            //retorna los caracteres leidos hasta el momento
            if (aux == 0){
                return leido;
            }
            if (aux == -1){
                /*
                 * errno indica el tipo de error.
                 * caso EINTR, si ocurre una interrupcion antes de leer
                 * caso EGAIN, el socket no esta disponible
                 * Ambos errores tratan una espera de 100 s
                 * y se vuelve a intentar.
                 */
                switch (errno){
                    case EINTR:
                    case EAGAIN:
                        usleep(100);
                        break;
                    default:
                        return -1;

                }
            }
        }
    }
    /*
     * retorna el total de los caracteres leidos
     */
    return leido;

}

/*
 * Devuelve numero de bytes escritos;
 * -1 si hay algun error.
 */
int Socket::escribirSocket(int fd, char *Datos, int Longitud) {
    int escrito = 0;
    int aux = 0;

    /*
     * comprobacion de los parametros de entrada
     */
    if ((fd == -1) || (Datos == NULL) || (Longitud < 1)){
        return -1;
    }

    /*
     * ciclo hasta que se haya escrito todos los caracteres
     * que nos han indicado.
     */
    while (escrito < Longitud){
        aux = write(fd, Datos + escrito, Longitud - escrito);
        if (aux > 0){
            //si se escribe caracteres, se actualiza
            //la variable escrito
            escrito = escrito + aux;
        }
        else{
            //si se cierra el socket, se devuelve el numero de
            //de caracteres leidos.
            //si hay error retorna -1.
            if (aux == 0){
                return escrito;
            }
            else{
                return -1;
            }
        }

    }

    /*
     * devolvemos el total de caracteres leidos
     */
    return escrito;


}
