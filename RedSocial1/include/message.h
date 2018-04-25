#ifndef MESSAGE_H
#define MESSAGE_H

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

/**
 * @brief The Socket class, thought to contain socket usage methods (UDP protocol)
 *          Totalmente original y para nada reutilizada
 */

class Socket
{
    int fd_;        //FILE DESCRIPTOR
    int result_;    //BIND RESULT

public:
    Socket(const sockaddr_in& address);     ///<@brief Constructor
    ~Socket();                              ///<@brief Destructor by default. Closes socket file

    int get_fd(){ return fd_; }             ///<@brief Getter for file descriptor
    int get_result(){ return result_; }     ///<@brief Getter for bind result

    void send_to(const Message& message, const sockaddr_in& remote_address);    ///<@brief Sends message to a certain address
    void recieve_from(int fd, Message& message, sockaddr_in& address);          ///<@brief Recieves message from a certain address
//private:
  //  sockaddr_in make_ip_address(const std::string& ip_address, int port);
};

}

#endif // MESSAGE_H
