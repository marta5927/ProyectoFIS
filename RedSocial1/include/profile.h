
#ifndef PROFILE_H
#define PROFILE_H

#include "message.h"

namespace FIS{

struct infoUser{
    std::string name;     //Nombre comun de usuario
    std::string passwd;   //Contraseña -> El cifrado y los asuntos de seguridad los dejaría para más adelante
    int edad;             //Duh
    std::string phoneNumber; // Número de teléfono
    std::string location; // Localidad o domicilio
    //...    Por si falta algo necesario

};
// Posibilidad de añadir si un usuario es menor de X edad que no se pueda crear la cuenta

class Profile{
private:
    int UserID_;        //Identificador numerico de usuario
    infoUser data_;

    int TLFD_;          //TimeLine file descriptor, porque somos bilingües
        //La idea es que almacene los identificadores de los mensajes propios
    std::vector<FIS::Message> MensajesUsu_;

public:
    Profile(infoUser data_, int UserID);          //Recibir -> Datos de usuario, se le solicitan al crear la cuenta
    //Profile();        //Configurar el constructor para que pueda obtener los datos del fichero de texto también
                        //Así podemos preservar los cambios y las cuentas de usuario entre ejecuciones
    ~Profile();         //Dudo que tenga que hacer gran cosa

    //Getters y setters para atributos y posibles cambios de datos que quiera hacer el usuario

};
    
   Profile(infoUser data_, int UserID){
       
    ofstream profile;
	profile.open("perfil.txt", ios::out);

	//profile << "ID" << "::"<< "Nombre" << "::"<< "Constraseña" << "::"<< "Edad" << "::" << "Teléfono" << "::"<< "Localidad" << endl;
    profile << UserID << "::"<< data_.name << "::"<< data_.passwd << "::"<< data_.edad << "::"<< data_.phoneNumber << "::"<< data_.location << endl;
    
       
   }

}



#endif // PROFILE_H
