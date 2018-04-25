#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include <cxxabi.h>
#include <getopt.h>             //Command line opt
#include <mutex>
#include <set>
#include <utility>
#include <cstdlib>

#include "history.h"

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

class ServerController{
private:
    //std::vector<FIS::Profile> UserProfiles_;      Encapsulado dentro de History va mejor,
    FIS::History history_;
    //FIS::Socket socket_;        El socket probablemente vaya en el main. Está por ver
    std::mutex mutex_;

public:
    ServerController();
    ~ServerController();

    void server_receive(std::atomic<bool>& quit, Socket receiver, std::set<std::pair<int, std::string> >& user_list, History history);
    void server_send(std::atomic<bool>& quit, Socket receiver, const std::set<std::pair<int, std::string> >& user_list,
                     const std::string& username, History history);

    /*
     * void ControlLogin();
     * void CrearCuenta(//nombredeusuario);
     * void DarAcceso();   //-> señal a cliente. Mostrar menú
     *
     * void EditarPerfil(//indice de perfil a editar, //a quién se lo muestro);
     * void MostrarPerfil(//indice de perfil a mostrar, //a quién se lo muestro);
     * void MostrarTimeline(//mostrar timeline de quién, //a quién se lo muestro,);
     *                      //Manejar dentro de manera interactiva si muestra la general, me gustas o retweets
     *
     *
    */
};

}

#endif // SERVERCONTROLLER_H
