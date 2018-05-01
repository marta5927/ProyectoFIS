#include "/home/marta/Descargas/ProyectoFIS-master/RedSocial-Client1/include/socket.h"


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

void Socket::send_to(const Message& message, const sockaddr_in& address){

 //std::cout << fd_ << std::endl;

   int result = sendto(fd_, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&remote_address), sizeof(remote_address));

   if(result < 0){

        std::cout << result << std::endl;
        throw std::system_error(errno, std::system_category(), "fallo en el envio del mensaje");

   }
 }

 void Socket::recieve_from(int fd, Message& message, sockaddr_in& address){

    socklen_t src_len = sizeof(address);

        int result = recvfrom(fd, &message, sizeof(message), 0
               , reinterpret_cast<sockaddr*>(&address), &src_len);
        if(result < 0){
            throw std::system_error(errno, std::system_category(), "fallo la recepcion del mensaje");
        }

        // Mostrar el mensaje recibido en la terminal
        //cambiar a la clase cliente
 /*             char* remote_ip = inet_ntoa(address.sin_addr);
              int remote_port = ntohs(address.sin_port);
          message.text[1023] = '\0';
          std::cout << "\n"
                    << "\nUsuario " << message.user
                    << "\nHora: " << message.tiempo
                    << "\nDireccion " << remote_ip << ":" << remote_port
                    << "\nMensaje '" << message.text << "'\n";

        */
 }


 void Socket::send_usu(const User&usu, const sockaddr_in& address){

     int result = sendto(fd_, &usu, sizeof(usu), 0, reinterpret_cast<const sockaddr*>(& address), sizeof(address));

         if (result < 0) {
             throw std::system_error(errno, std::system_category(), "No se pudo enviar el usuario \n");
         }
         else{
             std::cout << "Usuario enviado correctamente \n";


     }
}


 void Socket::recieve_confir(std::string& confir, sockaddr_in& address){

     socklen_t src_len = sizeof(address);

     int result = recvfrom(fd_, &confir, sizeof(confir), 0, reinterpret_cast<sockaddr*>(&address), &src_len);

         if (result < 0) {
             throw std::system_error(errno, std::system_category(), "No se pudo recibir la confirmacion");
         }


 }



 void Socket::send_infoUser(const InfoUser& info, const sockaddr_in& address){

     int result = sendto(fd_, &info, sizeof(info), 0, reinterpret_cast<const sockaddr*>(& address), sizeof(address));

         if (result < 0) {
             throw std::system_error(errno, std::system_category(), "No se pudo enviar la informacion \n");
         }
         else{
             std::cout << "Infomacion de usuario enviada correctamente \n";


     }
 }
