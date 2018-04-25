#include "../include/servercontroller.h"

using namespace FIS;

int main(int argc, char* argv[]){

    std::string port_opt, ip_addr, n_user;
    bool help_opt, serv_opt;

    procesamiento_de_opciones(help_opt, serv_opt, port_opt, ip_addr, n_user, argc, argv);




    return 0;
}
