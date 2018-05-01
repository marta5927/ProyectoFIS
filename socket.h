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
using namespace FIS;

class Socket {

    private:
        int fd_;        //FILE DESCRIPTOR
        int result_;    //BIND RESULT

    public:
        Socket();
        Socket(const sockaddr_in&);
        ~Socket();

        int get_fd(){ return fd_; }
        int get_result(){ return result_; }

        void send_to(const Message&, const sockaddr_in&);    ///<@brief Sends message to a certain address
        void recieve_from(int fd, Message&, sockaddr_in&);          ///<@brief Recieves message from a certain address

        void send_usu(const User&, const sockaddr_in&);
        void recieve_confir(std::string&, sockaddr_in&);

        void send_infoUser(const InfoUser&, const sockaddr_in&);

};

#endif // SOCKET_H
