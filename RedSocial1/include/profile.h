#ifndef PROFILE_H
#define PROFILE_H

#include "message.h"

namespace FIS{

struct InfoUser{
    std::string name;     //Nombre comun de usuario
    std::string passwd;   //Contraseña -> El cifrado y los asuntos de seguridad los dejaría para más adelante
    int edad;             //Duh

    //...    Por si falta algo necesario

};

class Profile{
private:
    int UserID_;        //Identificador numerico de usuario
    InfoUser data_;

    int TLFD_;          //TimeLine file descriptor, porque somos bilingües
        //La idea es que almacene los identificadores de los mensajes propios
    std::vector<FIS::Message> MensajesUsu_;

public:
    Profile();          //Recibir -> Datos de usuario, se le solicitan al crear la cuenta
    //Profile();        //Configurar el constructor para que pueda obtener los datos del fichero de texto también
                        //Así podemos preservar los cambios y las cuentas de usuario entre ejecuciones
    ~Profile();         //Dudo que tenga que hacer gran cosa

    //Getters y setters para atributos y posibles cambios de datos que quiera hacer el usuario

};

}



#endif // PROFILE_H
