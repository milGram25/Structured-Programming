/*********PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 15 de marzo de 2024
PROGRAMA: sets.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Un programa que permite manipular y realizar operaciones de dos conjuntos.
*************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include "set_functions.cpp"

using namespace std;

int sizea,sizeb,set,opt,optSet,operation;
bool valid=false,finish=false;

int main(){
    //Darte tamaño a las matrices
    do{
    cout<<"De que tamano desea que sea su conjunto 1? Minimo 5"<<endl;
    cin>>sizea;
    if(sizea<5){
        cout<<"Tamaño invalido"<<endl;
        valid=false;
    } else {
        valid=true;
    }
    } while (valid==false);
    do{
    cout<<"De que tamano desea que sea su conjunto 2? Minimo 5"<<endl;
    cin>>sizeb;
    if(sizeb<5){
        cout<<"Tamaño invalido"<<endl;
        valid=false;
    } else {
        valid=true;
    }
    } while (valid==false);
    char seta[sizea],setb[sizeb];
    emptySet(seta,sizea);
    emptySet(setb,sizeb);

    do{
        finish=menu(seta,setb,sizea,sizeb);
    } while (finish==false);
}
