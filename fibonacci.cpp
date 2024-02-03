/****PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 9 de febrero de 2024
PROGRAMA: fibonacci.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Imprimir una serie Fibonacci con distintos ciclos.
**************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a,b,c,opt,series;
    char again;
    do{
        //Reiniciar variables.
        a=0;
        b=1;
        c=1;
        //Solicitar valores
        cout<<"Hasta que numero desea realizar la serie Fibonacci?"<<endl;
        cin>>series;
        cout<<"Que ciclo desea utilizar?"<<endl<<"1.for"<<endl<<"2.while"<<endl<<"3.do-while"<<endl;
        cin>>opt;
        //Varios ciclos
        switch(opt){
            case 1:
                cout<<a<<endl;
                for(c=0;c<=series;c=c){
                    cout<<c<<endl;
                    c=a+b;
                    a=b;
                    b=c;
                }
                break;
            case 2:
                cout<<a<<endl;
                cout<<b<<endl;
                while(c<=series){
                    cout<<c<<endl;
                    a=b;
                    b=c;
                    c=a+b;
                }
                break;
            case 3:
                cout<<a<<endl;
                do{
                    cout<<c<<endl;
                    a=b;
                    b=c;
                    c=a+b;
                }while(c<=series);
                break;
            default:
                cout<<"Opcion invalida."<<endl;
        }
        //Repetir ejecución.
        cout<<"Ingrese E para salir del programa. De lo contrario, se volvera a ejecutar."<<endl;
        cin>>again;
    }while(again!='E');
}