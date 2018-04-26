#include <iostream>

using namespace std;

/*
 * Funcion que muestra las opciones al iniciar la
 * red social
 *
 * En principio todas las cuentas se concideran privadas
 * Futura mod: acceder sin tener cuenta
 */
int menu_inicio(){
    
    cout << " \t >>> Bienvenide a nuestra red social " << endl;
    
        cout << "\t\t 1.- Iniciar sesion" << endl;
        cout << "\t\t 2.- Crear cuenta " << endl;
        cout << "\t\t ------------------- " << endl;
        cout << "\t\t Intr. 0 para salir " << endl;
        int opcion;
            do {
                cout << " \t >> Intr. una opcion: ";
                cin >> opcion;
            }while((opcion > 2) || (opcion < 0));

    return opcion;
}

/*
 *Funcion que se encarga de iniciar sesion
 * Devolvera 0 si no hay ningun problema 
 * y -1 en caso contrario
 *
 * Probablemente habra que pasarle el controlador
 * del cliente por parametros, encargado de 
 * comunicarse con el servidor
 *
 */
int iniciar_sesion(){ }


/*
 *Funcion que se encarga de crear cuenta
 * Devolvera 0 si no hay ningun problema 
 * y -1 en caso contrario
 *
 * Probablemente habra que pasarle el controlador
 * del cliente por parametros, encargado de 
 * comunicarse con el servidor
 *
 */
int crear_cuenta(){ }

/*
 * Funcion que se encarga de mostrar
 * las opciones dentro de la cuenta
 *
 */
int menu_cuenta(){


    cout << " \t >>> Menu de la cuenta " << endl;
    
        cout << "\t\t 1.- " << endl;
        cout << "\t\t 2.- " << endl;
        cout << "\t\t ------------------- " << endl;
        cout << "\t\t Intr. 0 para salir " << endl;
        int opcion;
            do {
                cout << " \t >> Intr. una opcion: ";
                cin >> opcion;
            }while((opcion > 2) || (opcion < 0));

    return opcion;
}


/*
 *Funcion que se encarga de gestionar
 * las opciones de la cuenta tras 
 * iniciar sesion
 */
void opciones_cuenta(){

    int opcion;
    
    do {
        
        opcion = menu_cuenta();
            
            switch(opcion){
                case 0:
                    cout << " 0.- Salir" << endl;
                    break;
                case 1:
                    cout << " 1- " << endl;
                      
                    break;
                case 2:
                    cout << " 2.- " << endl;
                    
                    break;
                default:
                    cout << " opcion " << opcion << " no valida " << endl;
            
            } 
    
    }while (opcion != 0);

}


/*
 * Falta añadir el controlador del cliente
 */
int main()
{
    int opcion;
        do {
            opcion = menu_inicio();
            
            switch(opcion){
                case 0:
                    cout << " 0.- Salir" << endl;
                    break;
                case 1:
                    cout << " 1- Iniciar sesion" << endl;
                        if(iniciar_sesion() == 0)
                            opciones_cuenta();
                        else
                            cout << " Error al iniciar sesion" << endl;
                    
                    break;
                case 2:
                    cout << " 2.- Crear cuenta" << endl;
                        if(crear_cuenta() == 0)
                            cout << " Cuenta creada correctamente " << endl;
                        else
                            cout << " Error al crear la cuenta" << endl;
                    
                    break;
                default:
                    cout << " opcion " << opcion << " no valida " << endl;
            
            }
            
        }while( opcion =! 0);
    
    cout << " Saliendo.." << endl;
    
    return 0;
}
