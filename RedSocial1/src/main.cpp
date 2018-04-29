#include "../include/servercontroller.h"

int main(int argc, char* argv[]){

    FIS::Message msg;
    const int SERVER_PORT = 7777;
    sockaddr_in my_addr{};

    try{
        my_addr = FIS::make_ip_address("", SERVER_PORT);     //MAKE_IP_ADDR usará INADDR_ANY -> Acepta conexiones a cualquier IP del server
        std::atomic<bool> quit(false);

        FIS::ServerController server(my_addr);

    }catch(std::system_error& e){
        std::cerr << program_invocation_name << ": " << e.what() << '\n';
        return 6;
    }
    catch(int e){
        std::cerr << "Error " << e << ": problemilla\n";
    }

    return 0;
}
