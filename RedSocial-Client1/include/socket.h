#ifndef SOCKET_H
#define SOCKET_H

#include <cxxabi.h>
#include <getopt.h>             //Command line opt
#include <iostream>
#include <string>               //String
#include <sys/socket.h>         //Unix sockets
#include <sys/types.h>
#include <netinet/ip.h>         //ipaddr
#include <arpa/inet.h>          //
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <cerrno>               //errno
#include <cstring>
#include <cstdio>               //C-like methods
#include <cstdlib>
#include <unistd.h>             //UNIX STANDAR
#include <vector>
#include <system_error>         //Errores de sistema
#include <exception>
#include <thread>
#include <atomic>
#include <pthread.h>

#include "profile.h"
  
    
//Hacerlo un struct facilita el acceso desde otras clases a los campos del mensaje
//Sujeto a cambios de ser necesario****
struct Message{

    Message() {}
    char username[90];          //El campo de username tiene una longitud de caracteres arbitraria
    char text[281];

    unsigned int ID;            //El campo es necesario para la organización de los mensajes en la base de datos
    int TimeOfLife;             //El campo es necesario para la posible implementación de un orden cronológico

    //Campos para MG, RT y Comments ... FUTURA IMPLEMENTACION
};
struct InfoUser{
    std::string name;     //Nombre comun de usuario
    std::string passwd;   //Contraseña -> El cifrado y los asuntos de seguridad los dejaría para más adelante
    int edad;             //Duh

    //...    Por si falta algo necesario

};



class Socket {

    private:
        int fd_;        //FILE DESCRIPTOR
        int result_;    //BIND RESULT

    public:
        Socket();
        Socket( const sockaddr_in&);
        ~Socket();

        int get_fd(){ return fd_; }
        int get_result(){ return result_; }

        void send_to(const Message&, const sockaddr_in&);    ///<@brief Sends message to a certain address
        void send_infoUser(const InfoUser&, const sockaddr_in&);

        void recieve_from( Message&, sockaddr_in&);          ///<@brief Recieves message from a certain address
        void recieve_confir(bool&, sockaddr_in&);


};

#endif // SOCKET_H
