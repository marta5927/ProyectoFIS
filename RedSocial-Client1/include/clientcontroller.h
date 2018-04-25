#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <cxxabi.h>
#include <getopt.h>             //Command line opt
#include <mutex>
#include <set>
#include <utility>
#include <cstdlib>

#include "profile.h"

namespace FIS{

/**
 * @brief Option processing for terminal argument inputs
 * @param help_option
 * @param server_option
 * @param port_option
 * @param ip_addr
 * @param argc
 * @param argv
 */
void procesamiento_de_opciones(bool& help_option, bool& server_option, std::string& port_option,
                               std::string ip_addr, std::string& n_user, int argc, char* argv[]){

    static struct option long_options[] ={
          {"help",      no_argument,       0, 'h'},
          {"server",    no_argument,       0, 's'},
          {"client",    required_argument, 0, 'c'},
          {"port",      required_argument, 0, 'p'},
          {"user",      required_argument, 0, 'u'},
          {0, 0, 0, 0}
    };
    int option_index = 0;
    int c;
    while ( (c = getopt_long(argc, argv, "hsc:p:u:", long_options, &option_index)) != -1) {
        switch (c) {
        case 'h':
            help_option = true;
            break;
        case 's':
            server_option = true;
            break;
        case 'p':       //opcion guardada en optarg
            port_option = std::string(optarg);
            //cout << port_option << endl;
            break;
        case 'c':
            ip_addr = std::string(optarg);
            //cout << ip_addr << endl;
            break;
        case 'u':
            n_user = std::string(optarg);
            break;
        case '?':
            //Error message already sent
            break;
        default:
            std::fprintf(stderr, "?? getopt devolvió código "
                    "de error 0%o ??\n", c);
            break;
        }
    }
    if (optind < argc) {
        std::cout << "-- argumentos no opción --\n";
        for (; optind < argc; ++optind) {
            std::cout << "argv[" << optind << "]: " <<
            argv[optind] << '\n';
        }
    }
}

class ClientController{
private:

    FIS::Profile ClientProfile_;
    //FIS::Socket socket_;        El socket probablemente vaya en el main. Está por ver
    std::mutex mutex_;

public:
    ClientController();
    ~ClientController();

    void UserSend(std::atomic<bool>& quit, Socket receiver);
    /*
     * void ControlLogin();
     * void CrearCuenta(//nombredeusuario);
     * void SolicitarAcceso();   //-> señal a server
     *
    */
};

}

#endif // CLIENTCONTROLLER_H
