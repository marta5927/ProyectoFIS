#include "/home/marta/Descargas/ProyectoFIS-master/RedSocial-Client1/include/clientcontroller.h"
#include "/home/marta/Descargas/ProyectoFIS-master/RedSocial-Client1/include/profile.h"

using namespace FIS;


sockaddr_in make_ip_address(const std::string& ip_address, int port){

    sockaddr_in aux{};
    aux.sin_family = AF_INET;

        if(ip_address.empty())
            aux.sin_addr.s_addr = htonl(INADDR_ANY);
        else {

            char ip[255];
            strcpy(ip, ip_address.c_str());
            ip[254]='\0';
            inet_aton(ip, &aux.sin_addr);
        }

    aux.sin_port = htons(port);
    return aux;

}




void procesamiento_de_opciones(sockaddr_in &dir_servidor, sockaddr_in &dir_cliente, int argc, char* argv[]){


    bool help_option = false;
    std::string ip_addr;
    std::string port_opcion;
    static struct option long_options[] ={
          {"help",      no_argument,       0, 'h'},
          {"client",  required_argument, 0, 'c'},
          {"port",      required_argument, 0, 'p'},
          {0, 0, 0}
    };


    int option_index = 0;
    int c;
    while ( (c = getopt_long(argc, argv, "hc:p:", long_options, &option_index)) != -1) {
        switch (c) {

        case 'h':
            help_option = true;
            break;

        case 'c':
             std::printf("opción c con valor '%s'\n", optarg);
             ip_addr = std::string(optarg);
             break;

        case 'p':       //opcion guardada en optarg
            std::printf("opción p con valor '%s'\n", optarg);
            port_option = std::string(optarg);
            break;

        case '?':
            help_option = true;//Error message already sent
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


    if(help_option)
        std::cout << "Usage: [-c|--client client_ip] [-p|--port server_port] client\n";

        int port;
        std::string remote = "";
        sockaddr_in dir_servidor{};
        sockaddr_in dir_cliente{};

        if (port_option.size() != 0)
            port = std::stoi(port_option); //stoi(string ) convierte en int

            dir_servidor = make_ip_address("127.0.0.1", 0);
            dir_cliente = make_ip_address(ip_addr, port);


}


ClientController::ClientController(){}

ClientController::ClientController(sockaddr_in dir_servidor_,
                                   sockaddr_in dir_cliente_): ClientProfile_(),
                                                              socket_(dir_servidor_),
                                                             dir_servidor(dir_servidor_),
                                                             dir_cliente(dir_cliente_)
{


}

void ClientController::UserSend(std::atomic<bool> &quit ){

    while(!quit){
        std::string message_test;
        std::getline(std::cin, message_test);

        if(message_test == "/quit")
            quit = true;
        else{

            FIS2::Message message;
            strcpy(message.text, message_test.c_str());
            message.text[280] = '\0';

            socket_.send_to(message, dir_servidor);
        }

    }
}

int ClientController::ControlLogin(const User& usu){

    socket_.send_usu(usu, dir_servidor);

    std::string confir = "";
    socket_.recieve_confir(confir, dir_servidor);

    if(!confir.empty())
        return 0;
    return -1;
}


int ClientController::CrearCuenta(const InfoUser& info){

    socket_.send_infoUser(info, dir_servidor);

    std::string confir = "";
    socket_.recieve_confir(confir, dir_servidor);

    if(!confir.empty())
        return 0;
    return -1;

}

