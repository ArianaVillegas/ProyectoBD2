#ifndef REGISTRO_H
#define REGITRO_H
#include <bits/stdc++.h>
using namespace std; 

struct Registro
{
    char codigo[5] = { };
	char Nombre[12] = { };
	char Apellidos[20] = { };
    char Carrera[20] = { };
    Registro(){};
    Registro(char* _cod, char* _nombre, char* _apellido ,char* _carrera){
        strncpy(codigo, _cod, 5);
        strncpy(Nombre, _nombre, 12);
        strncpy(Apellidos, _apellido, 20);
        strncpy(Carrera, _carrera, 20);
    };
    void setData(){
        string line;
        cin.ignore();
        cout << "\nCodigo: ";
        getline(cin,line);
        strncpy(codigo, line.c_str(), 5);
        cout << "Nombre: ";
        getline(cin,line);
        strncpy(Nombre, line.c_str(), 12);
        cout << "Apellidos: ";
        getline(cin,line);
        strncpy(Apellidos, line.c_str(), 20);
        cout << "Carrera: ";
        getline(cin,line);
        strncpy(Carrera, line.c_str(), 20);
    };
    void showData(){
        
        string cod = codigo;
        string nomb = Nombre;
        string ap = Apellidos;
        string Carre = Carrera;                
        cout << "\nCodigo: ";
        cout << cod;
        cout << "\nNombre: ";
        cout << nomb;
        cout << "\nApellidos: ";
        cout << ap;
        cout << "\nCarrera: ";
        cout << Carre;
        cout << "\n----------------\n";    
    }
    void showData(int mode){
        
        string cod = codigo;
        string nomb = Nombre;
        string ap = Apellidos;
        string Carre = Carrera;

        switch (mode){
            case 0:{
                
            cout << "\nCodigo: ";
            cout << cod;
            cout << "\nNombre: ";
            cout << nomb;
            cout << "\nApellidos: ";
            cout << ap;
            cout << "\nCarrera: ";
            cout << Carre;
            cout << "\n----------------\n"; 
            return;   
            break;
            }
            case 1:{
                cout << "\nCodigo: ";
                cout << cod;
                cout << "\n----------------\n";
             
                break;
            }
            case 2:{
                cout << "\nNombre: ";
                cout << nomb;
                cout << "\n----------------\n";
              
                break;
            }
            case 3:{

                cout << "\nApellidos: ";
                cout << ap;                    
                cout << "\n----------------\n";    
        
                break;
            }
            case 4:{
                cout << "\nCarrera: ";
                cout << Carre;
                cout << "\n----------------\n";    
                break;
            }
        }


        
        };
};

#endif