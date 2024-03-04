/*********PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 04 de marzo de 2024
PROGRAMA: matrix.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Un programa que trabaja con dos matrices, puede realizar operaciones de suma, resta y multiplicacion, un llenado manual y aleatorio, y tratado de los elementos.
**************************************************************/

#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    int sizea,sizeb,column,row,i,j,a,suma,sumb,columna,rowa,columnb,rowb,editMat,edit,opt,count,rest,mult;
    char confirm;
    bool exit=false,valid=false;

    //Inizializar randomizador
    srand(time(NULL));
    a=rand()%201;

    //Tamaño de Matriz A
    do{
    cout<<"De que tamano sera el lado de su matriz A?"<<endl;
    cin>>sizea;
    if(sizea>10||sizea<2){
        cout<<"Tamano invalido."<<endl;
        valid=false;
    } else {
        valid=true;
    }
    } while (valid==false);
    
    //Tamaño de Matriz B
    do{
    cout<<"De que tamano sera el lado de su matriz B?"<<endl;
    cin>>sizeb;
        if(sizeb>10||sizeb<2){
        cout<<"Tamano invalido."<<endl;
        valid=false;
    } else {
        valid=true;
    }
    } while (valid==false);

    int matra[10][10],matrb[10][10];

    //Vaciar matriz A
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            matra[i][j]=NULL;
        }
    }

    //Vaciar matriz B
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            matrb[i][j]=NULL;
        }
    }

    do{
        do{
        cout<<"Que desea hacer?\n1.Ingresar valores\n2.Llenar matriz con valores aleatorios\n3.Realizar una operacion con las matrices\n4.Mostrar matriz\n5.Editar elementos\n6.Vaciado de matrices\n7.Salir"<<endl;
        cin>>opt;
        if(opt<1||opt>7){
            cout<<"Opcion invalida"<<endl;
            valid=false;
        } else {
            valid=true;
        }
        } while (valid==false);
        switch(opt){
            case 1:
                //Ingresar
                do{
                cout<<"En que matriz desea añadir elementos?\n1.Matriz A\n2.Matriz B"<<endl;
                cin>>editMat;
                if(editMat<1||editMat>2){
                    cout<<"Opcion invalida"<<endl;
                    valid=false;
                } else {
                    valid=true;
                }
                }while(valid==false);
                cout<<"Cuantos datos ingresara?"<<endl;
                cin>>count;
                switch(editMat){
                    case 1:
                        //Ingresar valores Matriz A
                        for(i=0;i<count;i++){
                            cout<<"Cual es la columna donde desea ingresar el dato?"<<endl;
                            cin>>column;
                            cout<<"Cual es la fila donde desea ingresar el dato?"<<endl;
                            cin>>row;
                            cout<<"Cual es el dato a ingresar?"<<endl;
                            cin>>matra[row-1][column-1];
                        }
                        break;

                    case 2:
                        //Ingresar valores Matriz B
                        for(i=0;i<count;i++){
                            cout<<"Cual es la columna donde desea ingresar el dato?"<<endl;
                            cin>>column;
                            cout<<"Cual es la fila donde desea ingresar el dato?"<<endl;
                            cin>>row;
                            cout<<"Cual es el dato a ingresar?"<<endl;
                            cin>>matrb[row-1][column-1];
                        }
                        break;
                    }
                break;
            case 2:
                //Aleatorio
                cout<<"Que matriz desea rellenar aleatoriamente?\n1.Matriz A\n2.Matriz B"<<endl;
                cin>>editMat;
                switch(editMat){
                    case 1:
                        //Valores aleatorios Matriz A
                        srand(a);
                        for(i=0;i<sizea;i++){
                            for(j=0;j<sizea;j++){
                                if(matra[i][j]==NULL){
                                a=rand()%201-100;
                                matra[i][j]=a;
                                }
                            }
                        }
                        break;
                    case 2:
                        //Valores aleatorios Matriz B
                        srand(a);
                        for(i=0;i<sizeb;i++){
                            for(j=0;j<sizeb;j++){
                                if(matrb[i][j]==NULL){
                                    a=rand()%201-100;
                                    matrb[i][j]=a;
                                }
                            }
                        }
                }
                break;
            case 3:
                //Operacion
                cout<<"Que operacion desea realizar?\n1.Suma\n2.Resta\n3.Multiplicacion"<<endl;
                cin>>editMat;
                switch(editMat){
                    case 1:
                        //Sumar Matrices
                        suma=0;
                        sumb=0;
                        for(i=0;i<sizea;i++){
                            for(j=0;j<sizea;j++){
                                suma=suma+matra[i][j];
                            }
                        }
                        for(i=0;i<sizeb;i++){
                            for(j=0;j<sizeb;j++){
                                sumb=sumb+matrb[i][j];
                            }
                        }
                        cout<<"La suma de los datos en las matrices es: "<<suma+sumb<<endl;
                        break;
                    case 2:
                        //Restar Matrices
                        cout<<"Cual resta desea realizar?\n1.A-B\n2.B-A"<<endl;
                        cin>>rest;
                        switch(rest){
                            case 1:
                                //Resta de Matrices A-B
                                suma=0;
                                sumb=0;
                                for(i=0;i<sizea;i++){
                                    for(j=0;j<sizea;j++){
                                        suma=suma+matra[i][j];
                                    }
                                }
                                for(i=0;i<sizeb;i++){
                                    for(j=0;j<sizeb;j++){
                                        sumb=sumb+matrb[i][j];
                                    }
                                }
                                cout<<"La resta de los datos en las matrices A-B es: "<<suma-sumb<<endl;
                                break;
                            case 2:
                                //Resta de Matrices B-A
                                suma=0;
                                sumb=0;
                                for(i=0;i<sizea;i++){
                                    for(j=0;j<sizea;j++){
                                        suma=suma+matra[i][j];
                                    }
                                }
                                for(i=0;i<sizeb;i++){
                                    for(j=0;j<sizeb;j++){
                                        sumb=sumb+matrb[i][j];
                                    }
                                }
                                cout<<"La resta de los datos en las matrices B-A es: "<<sumb-suma<<endl;
                                break;
                        }
                        break;
                    case 3:
                        //Multiplicaciones
                        if(sizea==sizeb){
                            cout<<"Cual desea hacer?\n1.Multiplicar elementos individualmente\n2.Multiplicar toda la matriz"<<endl;
                            cin>>mult;
                        } else {
                            mult=1;
                        }
                        switch(mult){
                            case 1:
                                //Multiplicación de datos
                                cout<<"En que posicion se encuentra el dato a multiplicar de la Matriz A?\nColumna:\n";
                                cin>>columna;
                                cout<<"Fila:\n";
                                cin>>rowa;
                                cout<<"En que posicion se encuentra el dato a multiplicar de la Matriz B?\nColumna:\n";
                                cin>>columnb;
                                cout<<"Fila:\n";
                                cin>>rowb;
                                cout<<"El resultado de la multiplicacion es: "<<matra[rowa-1][columna-1]*matrb[rowb-1][columnb-1]<<endl;
                                break;
                            case 2:
                                //Multiplicar Matrices
                                for(i=0;i<sizea;i++){
                                    cout<<"|\t";
                                    for(j=0;j<sizea;j++){
                                        cout<<matra[i][j]*matrb[j][i]<<"\t";
                                    }
                                    cout<<"|\n";
                                }
                                break;
                        }
                }
                break;
            case 4:
                //Mostrar
                cout<<"Cual matriz desea mostrar?\n1.Matriz A\n2.Matriz B\n3.Ambas"<<endl;
                cin>>editMat;
                switch(editMat){
                    case 1:
                        //Imprimir matriz A
                        cout<<"Matriz A"<<endl;
                        for(i=0;i<sizea;i++){
                            cout<<"|\t";
                            for(j=0;j<sizea;j++){
                                cout<<matra[i][j]<<"\t";
                            }
                            cout<<"|\n";
                        }
                        cout<<endl;
                        break;
                    case 2:
                        //Imprimir matriz B
                        cout<<"Matriz B"<<endl;
                        for(i=0;i<sizeb;i++){
                            cout<<"|\t";
                            for(j=0;j<sizeb;j++){
                                cout<<matrb[i][j]<<"\t";
                            }
                            cout<<"|\n";
                        }
                        break;
                    case 3:
                        //Imprimir Ambas
                        cout<<"Matriz A"<<endl;
                        for(i=0;i<sizea;i++){
                            cout<<"|\t";
                            for(j=0;j<sizea;j++){
                                cout<<matra[i][j]<<"\t";
                            }
                            cout<<"|\n";
                        }
                        cout<<endl;

                        cout<<"Matriz B"<<endl;
                        for(i=0;i<sizeb;i++){
                            cout<<"|\t";
                            for(j=0;j<sizeb;j++){
                                cout<<matrb[i][j]<<"\t";
                            }
                            cout<<"|\n";
                        }
                        break;
                }
                break;
            case 5:
                //Borrado y edición
                cout<<"En que matriz desea editar el elemento?\n1.Matriz A\n2.Matriz B"<<endl;
                cin>>editMat;
                switch(editMat){
                    case 1:
                        cout<<"En que posicion se encuentra?\nFila:\n";
                        cin>>rowa;
                        cout<<"columna:\n";
                        cin>>columna;
                        cout<<"Desea editar o borrar el dato?\n1.Editar\n2.Borrar"<<endl;
                        cin>>edit;
                        switch(edit){
                            case 1:
                                cout<<"Cual sera el nuevo dato?"<<endl;
                                cin>>matra[rowa-1][columna-1];
                                break;
                            case 2:
                                cout<<"Ingrese S para confirmar."<<endl;
                                cin>>confirm;
                                if(confirm=='S'){
                                    matra[rowa-1][columna-1]=NULL;
                                } else {
                                    cout<<"Borrado cancelado."<<endl;
                                }
                                break;
                        }
                        break;
                    case 2:
                        cout<<"En que posicion se encuentra?\nFila:\n";
                        cin>>rowb;
                        cout<<"cloumna:\n";
                        cin>>columnb;
                        cout<<"Desea editar o borrar el dato?\n1.Editar\n2.Borrar"<<endl;
                        cin>>edit;
                        switch(edit){
                            case 1:
                                cout<<"Cual sera el nuevo dato?"<<endl;
                                cin>>matrb[rowb-1][columnb-1];
                                break;
                            case 2:
                                cout<<"Ingrese S para confirmar."<<endl;
                                cin>>confirm;
                                if(confirm=='S'){
                                    matrb[rowb-1][columnb-1]=NULL;
                                } else {
                                    cout<<"Borrado cancelado."<<endl;
                                }
                        }            
                }
                break;
            case 6:
                //Vaciar
                cout<<"Que matriz desea vaciar\n1.Matriz A\n2.Matriz B\n3.Ambas"<<endl;
                cin>>editMat;
                switch(editMat){
                    case 1:
                        //Vaciar matriz A
                        cout<<"Ingrese S para confirmar."<<endl;
                        cin>>confirm;
                        if(confirm=='S'){
                            for(i=0;i<10;i++){
                                for(j=0;j<10;j++){
                                    matra[i][j]=NULL;
                                }
                            }                                
                        } else {
                            cout<<"Vaciado cancelado."<<endl;
                        }
                        break;
                    case 2:
                        //Vaciar matriz B
                        cout<<"Ingrese S para confirmar."<<endl;
                        cin>>confirm;
                        if(confirm=='S'){
                            for(i=0;i<10;i++){
                                for(j=0;j<10;j++){
                                    matrb[i][j]=NULL;
                                }
                            }                                
                        } else {
                            cout<<"Vaciado cancelado."<<endl;
                        }
                        break;
                    case 3:
                        //Vaciar Ambas
                        cout<<"Ingrese S para confirmar."<<endl;
                        cin>>confirm;
                        if(confirm=='S'){
                            for(i=0;i<10;i++){
                                for(j=0;j<10;j++){
                                    matra[i][j]=NULL;
                                }
                            }
                            for(i=0;i<10;i++){
                                for(j=0;j<10;j++){
                                    matrb[i][j]=NULL;
                                }
                            }
                        } else {
                            cout<<"Vaciado cancelado."<<endl;
                        }
                        break;
                }
                break;
            case 7:
                //Salir
                exit=true;
                break;
        }
    } while (exit==false);

}