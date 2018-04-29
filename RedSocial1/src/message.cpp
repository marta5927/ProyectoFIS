#include "../include/message.h"
using namespace FIS;

/**
 * @brief make_ip_address   "Crea" el objeto sockaddr_in para usarla en el socket UDP para UNIX
 * @param ip_address        Puro postureo, en el servidor se usa la maravillosa INADDR_ANY
 * @param port              Puerto (Capa de Transporte) receptor. Fijado a 7777
 * @return                  Dirección local para Socket
 */
sockaddr_in FIS::make_ip_address(std::string ip_address, int port){
    //Control de errores de formato de entrada manejado en el bind***
    sockaddr_in local_address{};                            //inicializacion a 0
    local_address.sin_family = AF_INET;                     //dominio local
    if(ip_address == ""){
        local_address.sin_addr.s_addr = htonl(INADDR_ANY);      //32 bits
    }
    else{
        local_address.sin_addr.s_addr = inet_addr(ip_address.c_str());
    }
    local_address.sin_port = htons(port);                       //16 bits

    return local_address;
}

/**
 * @brief procesamiento_de_opciones     Intérprete de opciones largas al ejecutar por línea de comandos
 * @param help_option                   Probablemente acabemos implementando un modo administrador del servidor.
 *                                      Esto es toda la ayuda de momento
 * @param port_option                   Especifica por linea de comandos el puerto a usar.
 *                                      Lo interpreta como string y despues se convierte
 * @param argc                          Duh
 * @param argv                          Duh x2
 */
void FIS::procesamiento_de_opciones(bool& help_option, std::string& port_option, int argc, char* argv[]){
    static struct option long_options[] ={
          {"help",      no_argument,       0, 'h'},
          {"port",      required_argument, 0, 'p'},
          {0, 0, 0, 0}
    };

    int option_index = 0;
    int c;
    while ( (c = getopt_long(argc, argv, "hp:", long_options, &option_index)) != -1) {
        switch (c) {
        case 'h':
            help_option = true;
            break;
        case 'p':       //opcion guardada en optarg
            port_option = std::string(optarg);
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

/**
 * @brief Socket    Constructor a partir de la dirección obtenida (simple encapsulación)
 * @param address   Direccion tipo sockaddr_in a la que se "enlazará" el fichero socket
 */
Socket::Socket(const sockaddr_in& address){

    fd_ = socket(AF_INET, SOCK_DGRAM, 0);       //SOCK_DGRAM -> básicamente se usa para UDP, frente al
                                                //              SOCK_STREAM de TCP
    if(fd_ < 0){
        throw std::system_error(errno, std::system_category(), "no se pudo crear el socket");
    }
    else{
        result_ = bind(fd_, reinterpret_cast<const sockaddr*>(&address), sizeof(address));
        if(result_ < 0){
            throw result_;
        }
        std::cout << "Socket creado con exito" << std::endl;
    }
}

Socket::Socket(){}

Socket::~Socket(){
    close(fd_);
}

void Socket::send_to(const Message& message, const sockaddr_in& remote_address){

    //std::cout << fd_ << std::endl;

    int result = sendto(fd_, &message, sizeof(message),   //Envia desde mi socket "" a "198..." por 4444
        0, reinterpret_cast<const sockaddr*>(&remote_address), sizeof(remote_address));
    if(result < 0){
        std::cout << result << std::endl;
        throw std::system_error(errno, std::system_category(), "fallo en el envio del mensaje");
    }
}

void Socket::recieve_from(int fd, Message& messagerec, sockaddr_in& rem_address){

    socklen_t src_len = sizeof(rem_address);

    int result = recvfrom(fd, &messagerec, sizeof(messagerec), 0
           , reinterpret_cast<sockaddr*>(&rem_address), &src_len);
    if(result < 0){
        throw std::system_error(errno, std::system_category(), "fallo la recepcion del mensaje");
    }

}

