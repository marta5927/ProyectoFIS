#include <iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    cout << "Bienvenido a nuestra app" << endl;
    cout << "Desea registrarse o iniciar sesion:";
    string resp;
    int usu;
    cin >> resp;
    if(resp=="registrarme"){
        cout << "Ha elegido registrarse" << endl;
        ofstream registro("basddatos.txt");
        cout << "introduce tu nombre:";
        cin >> resp;
        registro << resp << ",";
        cout << "introduce tu apellido:";
        cin >> resp;
        registro << resp << ",";
        cout << "introduce tu nombre de usuario:";
        cin >> resp;
        registro << resp << ",";
        cout << "introduce tu contraseña";
        cin >> resp;
        registro << resp << ",";
        registro << endl;
    }
    else{
        cout << "Ha elegido iniciar sesion" << endl;
        string usuario,pass,prueba;
        cout << "Introduzca su nombre de usuario:";
        cin >> usuario;
       // cout << endl;
        cout << "Introduzca contraseña:";
        cin >> pass;
        ifstream registro("basddatos.txt");
        bool exito=false;
        while(exito==false){
            getline(registro,prueba);
            cout << "a\n";
            if(prueba.find(usuario)!= -1){
                if(prueba.find(",") != -1){
                    if(prueba.find(pass)!= -1){
                        cout << "Usuario correcto\n";
                        exito=true;
                        }
                    }
                }
            else{
                cout <<"Comprueba las credenciales"<<endl;
                cout << "Introduzca su nombre de usuario:";
                cin >> usuario;
                //cout << endl;
                cout << "Introduzca contraseña:";
                cin >> pass;
            }
            }
        }

        }
    //}


