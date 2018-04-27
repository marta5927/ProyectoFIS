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
