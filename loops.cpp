/****PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA:  de  de 2024
PROGRAMA: loops.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: 
**************************************************************/

#include <iostream>

using namespace std;

int num,sum,times;
char contin;

int main()
{
    do {
        times=times+1;
        num=0;
        cout<<"Ingrese un numero entero."<<endl;
        cin>>num;
        if(num>=0 && num<=500){
            for(int i = 0; i < 100; i++){
                sum=sum+5;
                cout<<sum<<endl;
            }
            }
        if(num>500 && num<=1000){
            for(int i = 0; i < 50; i++){
                sum=sum+10;
                cout<<sum<<endl;
            }
        }
        if (num>1000){
                cout<<"No se puede calcular el valor."<<endl;
        }
        cout<<"Ingrese N para cerrar el programa. Si no, volvera a ejecutarse."<<endl;
        cin>>contin;
    } while (contin!='N');
    cout<<"El programa se ejecuto "<<times<<" veces."<<endl;
}