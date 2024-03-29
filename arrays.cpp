/*********PRESENTACIÓN********
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
    //Inicializar el arreglo
    for(int i=0;i<10;i++){
        numbers[i]=0;
    }
    do{
        //Menu
        cout<<"Elija la opcion deseada.\n1. Anadir valores al arreglo\n2. Mostrar lista de valores\n3. Mostrar suma de valores\n4. Editar elemento\n5. Vaciar arreglo\n6. Finalizar"<<endl;
        cin>>opt;
        switch(opt){
            case 1:
                //Añadir valores en campos vacíos
                cout<<"Cuantos datos desea ingresar?"<<endl;
                cin>>times;
                sum=0;
                for(int k=0;k<10;k++){
                    if(numbers[k]==NULL){
                        sum++;
                    }
                }
                if(sum<times){
                    cout<<"No hay suficientes espacios vacios."<<endl;
                } else{
                for(int i=0;i<times;i++){
                    j=0;
                    for(j=0;j<10;j++){
                        if(numbers[j]==NULL){
                            cout<<"Ingrese valor. Se añadira al primer campo vacio."<<endl;
                            cin>>numbers[j];
                            j=10;
                        }
                    }
                }
                }
                break;
            case 2:
                //Imprimir arreglo
                for(int i=0;i<10;i++){
                    cout<<numbers[i]<<endl;
                }
                break;
            case 3:
                //Sumar arreglo
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
                        //Modificar valor
                        cout<<"Ingrese valor nuevo."<<endl;
                        cin>>numbers[pos-1];
                        break;
                    case 2:
                        //Eliminar  valor
                        numbers[pos-1]=NULL;
                        cout<<"Valor eliminado."<<endl;
                        break;
                    default:
                        cout<<"Opcion invalido."<<endl;
                }
                break;
            case 5:
                //Vaciar arreglo
                for(int i=0;i<10;i++){
                    numbers[i]=NULL;
                }
                break;
            case 6:
                //Finalizar programa
                exit=true;
                break;
            default:
                cout<<"Opcion invalida."<<endl;
        }
    } while(exit==false);
}