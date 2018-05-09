#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <cxxabi.h>
#include <getopt.h>             //Command line opt
#include <mutex>
#include <set>
#include <utility>
#include <cstdlib>

#include "profile.h"
#include "socket.h"


/**
 * @brief Option processing for terminal argument inputs
 */
void procesamiento_de_opciones( sockaddr_in &dir_servidor, sockaddr_in &dir_cliente,int argc, char* argv[]);


class ClientController{
private:

    //Profile ClientProfile_;
    Socket socket_;        //El socket probablemente vaya en el main. Está por ver
    //std::mutex mutex_;
    sockaddr_in dir_servidor;
    sockaddr_in dir_cliente;

public:
    sockaddr_in make_ip_address(const std::string& ip_address, int port);
    ClientController(std::string ip_server);
    ~ClientController();

    void UserSend(std::atomic<bool>& quit);
    void UserRecieve(std::atomic<bool>& quit);

     int ControlLogin(const InfoUser&);
     int CrearCuenta(const InfoUser& );
     //void SolicitarAcceso();   //-> señal a server


};



#endif // CLIENTCONTROLLER_H
