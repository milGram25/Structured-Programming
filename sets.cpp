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

using namespace std;

int sizea,sizeb,count,set,i,j,amountNull,pos,opt,optSet,operation;
bool valid=false,finish=false;
char k;

//Imprimie conjunto
void showSet(char sets[100],int size){
    cout<<"|\t";
    for(i=0;i<size;i++){
        if(sets[i]!=NULL){
            pos=i;
        }
    }
    for(i=0;i<=pos;i++){
        if(sets[i]!=NULL){
        cout<<sets[i]<<"\t";
        } else {
            cout<<"/\t";
        }
    }
    cout<<"|"<<endl;
}

//Ingresar datos al conjunto
void insertData(char sets[100],int size){
    cout<<"Cuantos datos desea ingresar?"<<endl;
    cin>>count;
    //Contar espacios vacíos
    amountNull=0;
    for(i=0;i<size;i++){
        if(sets[i]==NULL){
            amountNull++;
        }
    }
    //Ingresar valores a campos vacíos
    if(amountNull>=count){
        for(i=0;i<count;i++){
            if(sets[i]==NULL){
                cout<<"Ingrese dato en la posicion "<<i+1<<endl;
                cin>>sets[i];
            } else {
                count++;
            }
        }
    } else {
        cout<<"Tamano insuficiente de espacios vacios"<<endl;
    }
}

//Vaciar conjunto
void emptySet(char sets[100],int size){
    for(i=0;i<size;i++){
        sets[i]=NULL;
    }
}

//Modificar elementos
void editSet(char sets[100],int size){
    cout<<"En que posicion desea editar el elemento?"<<endl;
    do{
    cin>>pos;
    if(size>=pos){
        cout<<"Ingrese el nuevo elemento"<<endl;
        cin>>sets[pos-1];
        valid=true;
    } else {
        cout<<"Posicion fuera de rango. Ingrese posicion dentro del tamaño del conjunto."<<endl;
        valid=false;
    }
    } while (valid==false);
}

//Unión
void unionSet(char sets1[100],int sizes1,char sets2[100],int sizes 2){
    set_union()
}

//Intersección
void intersectionSet(char sets[100],int size){

}

//Diferencia
void differenceSet(char sets1[100],int sizes1,char sets2[100],int sizes2){
    //Crear universo
    char difference[sizes1];
    for(i=0;i<sizes1;i++){
        difference[i]=sets1[i];
    }

    //Eliminar repetidos
    for(i=0;i<sizes1;i++){
        for(j=0;j<sizes2;j++){
            if(difference[i]==sets2[j]){
                difference[i]=NULL;
            }
        }
    }

    //Imprimir diferencia
    cout<<"|\t";
    for(i=0;i<sizes1;i++){
        if(difference[i]!=NULL){
            cout<<difference[i]<<"\t";
        }
    }
    cout<<"|"<<endl;
}

//Complemento 
void complementSet(char sets[100],int size){
    //Crear universo
    char complement[70];
    j=0;
    for(k='0';k<='9';k++){
        complement[j]=k;
        j++;
    }
    for(k='A';k<='Z';k++){
        complement[j]=k;
        j++;
    }
    for(k='a';k<='z';k++){
        complement[j]=k;
        j++;
    }

    for(i=0;i<70;i++){
        for(j=0;j<size;j++){
            if(complement[i]==sets[j]){
                complement[i]=NULL;
            }
        }
    }

    cout<<"|\t";
    for(i=0;i<70;i++){
        if(complement[i]!=NULL){
            cout<<complement[i]<<"\t";
        }
    }
    cout<<"|"<<endl;
}

//Menu
bool menu(char set1[100],char set2[100],int size1,int size2){
    bool exit=false;

    cout<<"Que desea realizar?\n1.Ingresar elementos\n2.Editar elementos\n3.Vaciar conjuntos\n4.Realizar una operacion\n5.Mostrar conjuntos\n6.Salir"<<endl;
    cin>>opt;
    switch(opt){
        case 1://Ingresar elementos
            cout<<"En que conjunto desea ingresar elementos?\n1.Conjunto 1\n2.Conjunto 2"<<endl;
            cin>>optSet;
            switch(optSet){
                case 1://Ingresar elementos a Conjunto 1
                    insertData(set1,size1);
                    break;
                case 2://Ingresar elementos a Conjunto 2
                    insertData(set2,size2);
                    break;
            }
            break;
        case 2://Editar elementos
            cout<<"En que conjunto desea editar elementos?\n1.Conjunto 1\n2.Conjunto 2"<<endl;
            cin>>optSet;
            switch(optSet){
                case 1://Editar elementos en Conjunto 1
                    editSet(set1,size1);
                    break;
                case 2://Editar elementos en Conjunto 2
                    editSet(set2,size2);
                    break;
            }
            break;
        case 3://Vaciar conjuntos
            cout<<"Que conjunto desea vaciar?\n1.Conjunto 1\n2.Conjunto 2"<<endl;
            cin>>optSet;
            switch(optSet){
                case 1://Vaciar Conjunto 1
                    emptySet(set1,size1);
                    break;
                case 2://Vaciar Conjunto 2
                    emptySet(set2,size2);
                    break;
            }
            break;
        case 4://Operaciones con Conjuntos
            cout<<"Que operacion desea realizar?\n1.Union\n2.Interseccion\n3.Diferencia\n4.Complemento"<<endl;
            cin>>optSet;
            switch(optSet){
                case 1://Union
                    break;
                case 2://Interseccion
                    break;
                case 3://Diferencia
                    cout<<"Cual diferencia desea realizar?\n1.Conjunto 1 - Conjunto 2\n2.Conjunto 2 - Conjunto 1"<<endl;
                    cin>>operation;
                    switch(operation){
                        case 1://Diferencia 1-2
                            differenceSet(set1,size1,set2,size2);
                            break;
                        case 2://Diferencia 2-1
                            differenceSet(set2,size2,set1,size1);
                            break;
                    }
                    break;
                case 4://Complemento
                    cout<<"De que conjunto desea obtener el complemento?\n1.Conjunto 1\n2.Conjunto 2"<<endl;
                    cin>>operation;
                    switch(operation){
                        case 1://Complemento 1
                            complementSet(set1,size1);
                            break;
                        case 2://Complemento 2
                            complementSet(set2,size2);
                            break;
                    }
                    break;
            }
            break;
        case 5://Mostrar Conjuntos
            cout<<"Cual desea mostrar?\n1.Conjunto 1\n2.Conjunto 2\n3.Ambos"<<endl;
            cin>>optSet;
            switch (optSet){
                case 1://Mostrar Conjunto 1
                    showSet(set1,size1);
                    break;
                case 2://Mostrar Conjunto 2
                    showSet(set2,size2);
                    break;
                case 3://Mostrar Ambos
                    showSet(set1,size1);
                    showSet(set2,size2);
                    break;
            }
            break;
        case 6://Salida
            exit=true;
            break;
    }
    return exit;
}

int main(){
    //Darte tamaño a las matrices
    cout<<"De que tamano desea que sea su conjunto 1? Minimo 5"<<endl;
    cin>>sizea;
    cout<<"De que tamano desea que sea su conjunto 2? Minimo 5"<<endl;
    cin>>sizeb;
    char seta[sizea],setb[sizeb];
    emptySet(seta,sizea);
    emptySet(setb,sizeb);

    do{
        finish=menu(seta,setb,sizea,sizeb);
    } while (finish==false);
}
