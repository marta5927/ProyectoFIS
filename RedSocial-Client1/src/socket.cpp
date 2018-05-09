#include "../include/socket.h"


/**
 * @brief Socket    Constructor a partir de la dirección obtenida (simple encapsulación)
 * @param address   Direccion tipo sockaddr_in a la que se "enlazará" el fichero socket
 */
Socket::Socket(){}
Socket::Socket(const sockaddr_in& address){

    fd_ = socket(AF_INET, SOCK_DGRAM, 0);       //SOCK_DGRAM -> básicamente se usa para UDP, frente al
                                                    //              SOCK_STREAM de TCP
    if(fd_ < 0){
        throw std::system_error(errno, std::system_category(), "no se pudo crear el socket");
     }
     else{

        result_ = bind(fd_, (const sockaddr*)&address, sizeof(address));
        if(result_ < 0){
            throw result_;
         }
        std::cout << "Socket " << fd_ << " enlazado correctamente a la direccion: " << inet_ntoa(address.sin_addr) << '\n';
         std::cout << "Socket creado con exito" << std::endl;
     }
}
//10.150.28.109


Socket::~Socket(){
    //close(fd_);
}

void Socket::send_to(const Message& message, const sockaddr_in& address){

 //std::cout << fd_ << std::endl;

   int result = sendto(fd_, &message, sizeof(message), 0, (const sockaddr*)&address, sizeof(address));

   if(result < 0){

        std::cout << result << std::endl;
        throw std::system_error(errno, std::system_category(), "fallo en el envio del mensaje");

   }
 }

 void Socket::recieve_from( Message& message, sockaddr_in& address){

    socklen_t src_len = sizeof(address);

        int result = recvfrom(fd_, &message, sizeof(message), 0
               , reinterpret_cast<sockaddr*>(&address), &src_len);
        if(result < 0){
            throw std::system_error(errno, std::system_category(), "fallo la recepcion del mensaje");
        }

     
 }




 void Socket::recieve_confir(bool& confir, sockaddr_in& address){

     socklen_t src_len = sizeof(address);

     int result = recvfrom(fd_, &confir, sizeof(confir), 0, reinterpret_cast<sockaddr*>(&address), &src_len);

         if (result < 0) {
             throw std::system_error(errno, std::system_category(), "No se pudo recibir la confirmacion");
         }


 }



 void Socket::send_infoUser(const InfoUser& info, const sockaddr_in& address){

     int result = sendto(fd_, &info, sizeof(info), 0, (const sockaddr*)& address, sizeof(address));

         if (result < 0) {
             throw std::system_error(errno, std::system_category(), "No se pudo enviar la informacion \n");
         }
         else{
             std::cout << "Infomacion de usuario enviada correctamente \n";


     }
 }
