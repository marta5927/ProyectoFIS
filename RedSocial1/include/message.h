#ifndef MESSAGE_H
#define MESSAGE_H

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

namespace FIS{

sockaddr_in make_ip_address(std::string ip_address, int port);
void procesamiento_de_opciones(bool& help_option, std::string& port_option, int argc, char* argv[]);
struct Message{

    Message() {}
    char username[90];          //El campo de username tiene una longitud de caracteres arbitraria
    char text[281];

    unsigned int ID;            //El campo es necesario para la organización de los mensajes en la base de datos
    int TimeOfLife;             //El campo es necesario para la posible implementación de un orden cronológico

    //Campos para MG, RT y Comments ... FUTURA IMPLEMENTACION
};

class Socket
{
    int fd_;        //FILE DESCRIPTOR
    int result_;    //BIND RESULT

public:
    Socket();
    Socket(const sockaddr_in& address);
    ~Socket();

    int get_fd(){ return fd_; }
    int get_result(){ return result_; }

    void send_to(const Message& message, const sockaddr_in& remote_address);    ///<@brief Sends message to a certain address
    void recieve_from(int fd, Message& message, sockaddr_in& address);          ///<@brief Recieves message from a certain address

};

}

#endif // MESSAGE_H
