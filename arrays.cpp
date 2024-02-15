/****PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 21 de febrero de 2024
PROGRAMA: arrays.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Tratar los datos dentro de un arreglo de tamaño 10.
**************************************************************/

#include <iostream>

using namespace std;

int main(){
    int opt,sum,pos,edit,times,j;
    int numbers[10];
    bool exit=false;
    for(int i=0;i<10;i++){
        numbers[i]=0;
    }
    do{
        cout<<"Elija la opcion deseada.\n1. Añadir valores al arreglo\n2. Mostrar lista de valores\n3. Mostrar suma de valores\n4. Editar elemento\n5. Vaciar arreglo\n6.Finalizar"<<endl;
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Cuantos datos desea ingresar?"<<endl;
                cin>>times;
                for(int i=0;i<times;i++){
                    j=0;
                    for(j=0;j<10;j++){
                        if(numbers[j]==0){
                            cout<<"Ingrese valor. Se añadira al primer campo vacio."<<endl;
                            cin>>numbers[j];
                            j=10;
                        }
                    }
                }
                break;
            case 2:
                for(int i=0;i<10;i++){
                    cout<<numbers[i]<<endl;
                }
                break;
            case 3:
                sum=0;
                for(int i=0;i<10;i++){
                    sum=sum+numbers[i];
                }
                cout<<sum<<endl;
                break;
            case 4:
                cout<<"Que posicion de elemento desea editar."<<endl;
                cin>>pos;
                cout<<"Que desea hacer?\n1. Modificar valor\n2. Eliminar valor"<<endl;
                cin>>edit;
                switch(edit){
                    case 1:
                        cout<<"Ingrese valor nuevo."<<endl;
                        cin>>numbers[pos];
                        break;
                    case 2:
                        numbers[pos]=0;
                        cout<<"Valor eliminado."<<endl;
                        break;
                    default:
                        cout<<"Valor invalido."<<endl;
                }
                break;
            case 5:
                for(int i=0;i<10;i++){
                    numbers[i]=0;
                }
                break;
            case 6:
                exit=true;
                break;
            default:
                cout<<"Valor invalido."<<endl;
        }
    } while(exit==false);
}