/****PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 28 de Enero de 2024
PROGRAMA: user.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Un programa que recibe los datos del usuario y los muestra al final de la ejecución.
*****************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string name,age,place,birth,major,semester;

    //Solicitar datos
    cout<<"Ingrese su nombre."<<endl;
    getline(cin,name);
    cout<<"Ingrese su edad."<<endl;
    getline(cin,age);
    cout<<"Ingrese su lugar de residencia."<<endl;
    getline(cin,place);
    cout<<"Ingrese su fecha de nacimiento."<<endl;
    getline(cin,birth);
    cout<<"Ingrese su carrera."<<endl;
    getline(cin,major);
    cout<<"Ingrese su semestre."<<endl;
    getline(cin,semester);

    //Regresar información
    cout<<"¡Hola "<<name<<"!"<<endl;
    cout<<"Tu edad es: "<<age<<endl;
    cout<<"Vives en "<<place<<endl;
    cout<<"Naciste el "<<birth<<endl;
    cout<<"Estas cursando la carrera de "<<major<<" en el grado "<<semester<<endl;
}