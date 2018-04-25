#ifndef HISTORY_H
#define HISTORY_H

#include "profile.h"

namespace FIS {

/**
 * @brief The History class, meant to represent a Historic for our group chat
 */
class History{
private:
    int GeneralFD_;                              ///>@brief History File descriptor
    int InfoUsersFD_;

    //Probablemente sea mejor añadir la instancia de
    std::vector<FIS::Profile> PerfilesUsu_;
    //aquí. Es mejor almacenar los mensajes de cada usuario en su perfil y punto, manteniendo la copia del origial

    std::string path_;                  ///>@bried Directory path

public:
    History();                          ///>@brief Default constructor
    ~History();                         ///>@brief Default destructor

    int get_fd(){ return fd_; }

    void AddMessage(const Message& message, int UserID);   ///>@brief Adds message to a certain profile TL and General
    //....

    //Demás operaciones con mensajes

};

}

#endif // HISTORY_H
