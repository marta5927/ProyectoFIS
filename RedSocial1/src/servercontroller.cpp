#include "../include/servercontroller.h"

using namespace FIS;

ServerController::ServerController(const sockaddr_in &address){

    socket_ = Socket(address);
}

ServerController::~ServerController(){

}
void ServerController::ControlLogin(std::atomic<bool> &quit, const std::string &username, const std::string &passwd){


}

void ServerController::serverSend(std::atomic<bool> &quit, const std::string &username){

}

void ServerController::serverReceive(std::atomic<bool> &quit){

}
