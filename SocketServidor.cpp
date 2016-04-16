//
// Created by gustavo on 15/04/16.
//

#include "SocketServidor.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <err.h>


/*
 * Se le pasa el servicio que desea atender. Deja el socket
 * preparado para aceptar conexiones de clientes.
 *
 */

int SocketServidor::abreSocketUNIX(char *Servicio) {
    struct sockaddr_un direccion;
    int descriptor;

    /*
     * Se abre el socket
     */
    descriptor = socket(AF_UNIX, SOCK_STREAM, 0);
    if (descriptor == -1){
        return  -1;
    }

    /*
     * Se llena la estructura con los datos
     * para llamar la funcion bind()
     */
    strcpy(direccion.sun_path, Servicio);
    direccion.sun_family = AF_UNIX;

    if(bind(descriptor,(struct sockaddr *)&direccion,
            strlen(direccion.sun_path) + sizeof(direccion.sun_family)) == -1){

        //en casp de error cerramos el socket y devolvemos error
        close(descriptor);
        return -1;
    }

    /*
     * Avisamos al sistema que comience a recibir y atender las peticiones
     * de los clientes
     */
    if (listen(descriptor, 1) == --1){
        close(descriptor);
        return -1;
    }

    /**
     * se devuelve el descriptor del socketServidor
     */
    return descriptor;
}

/*
 * Se le pasa el socket de servidor y acepta en el una conexion de cliente.
 * devuelve el descriptor del socket del cliente o -1 si ocurre algun error
 */
int SocketServidor::aceptarConexionCliente(int descriptor) {

    socklen_t longitudCliente;
    struct sockaddr cliente;
    int hijo;

    /*
     * La llamada a la funcion accept requiere que el parametro
     * longitudCliente contenga inicialmente el tamaño de la estructura
     * cliente que se le pase.
     */
    longitudCliente = sizeof(cliente);
    hijo = accept(descriptor, &cliente, &longitudCliente);
    if (hijo == -1){
        return -1;
    }


    /**
     * se devuelve el descriptor en el que esta conetado el cliente
     */
    return hijo;
}


/*
 * Devuelve el descriptor del socket o -1 si ocurre algun error.
 * Recibe el nombre del servicio.
 */
int SocketServidor::abreSocketINET(char *Servicio) {
    struct sockaddr_in direccion;
    struct sockaddr cliente;
    socklen_t longitudCliente;
    struct servent *puerto;
    int descriptor;

    /*
     * Se abre el socket
     */
    descriptor = socket (AF_INET, SOCK_STREAM, 0);
    if (descriptor == -1){
        return -1;
    }

    /*
     * Se obtiene el servicio del fichero /etc/services
     */
    puerto = getservbyname (Servicio, "tcp");
    if (puerto == NULL){
        return -1;
    }

    /*
     * Se rellenan los campos de la estructura direccion, necesaria
     * para la llamada a la funcion bind()
     */
    direccion.sin_family = AF_INET;
    direccion.sin_port = puerto->s_port;
    direccion.sin_addr.s_addr = INADDR_ANY;
    if (bind(descriptor, (struct sockaddr *)&direccion, sizeof(direccion)) == -1){
        close(descriptor);
        return -1;
    }

    /*
     * se devuelve el descriptor del socket servidor
     */
    return descriptor;





}







