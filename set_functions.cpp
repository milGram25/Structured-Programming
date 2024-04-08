/*********PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 12 de abril de 2024
PROGRAMA: set_functions.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Un programa que permite manipular y realizar operaciones de dos conjuntos.
*************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Imprimie conjunto
void showSet(char sets[100],int size){
    int i,pos;
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
    int count,amountNull,i;
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
    for(int i=0;i<size;i++){
        sets[i]=NULL;
    }
}

//Modificar elementos
void editSet(char sets[100],int size){
    int pos;
    bool valid;
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
void unionSet(char sets1[100],int sizes1,char sets2[100],int sizes2){
    int i,j;
    bool repeat;
    vector <char> uniones (70);

    //Vaciar universo
    uniones.clear();

    //Duplicar primer conjunto
    for(i=0;i<sizes1;i++){
        uniones.push_back(sets1[i]);
    }

    //Inlcuir elementos no repetidos
    for(i=0;i<sizes2;i++){
        repeat=false;
        for(j=0;j<sizes1;j++){
            if(sets2[i]==uniones[j]){
                repeat=true;
            }
        }
        if(repeat==false){
            uniones.push_back(sets2[i]);
        }
    }

    //Ordenar elementos
    sort(uniones.begin(),uniones.end());

    //Imprimir unión
    cout<<"|\t";
    for(i=0;i<uniones.size();i++){
        if(uniones[i]!=NULL){
            cout<<uniones[i]<<"\t";
        }
    }
    cout<<"|"<<endl;
}

//Intersección
void intersectionSet(char sets1[100],int sizes1, char sets2[100],int sizes2){
    int i,j;
    bool repeat;
    vector <char> interseccion (70);

    interseccion.clear();

    for(i=0;i<sizes1;i++){
        interseccion.push_back(sets1[i]);
    }

    for(i=0;i<sizes1;i++){
        repeat=false;
        for(j=0;j<sizes2;j++){
            if(sets2[j]==interseccion[i]){
                repeat=true;
            }
        }
        if(repeat==false){
            interseccion[i]=NULL;
        }
    }

    sort(interseccion.begin(),interseccion.end());

    cout<<"|\t";
    for(i=0;i<interseccion.size();i++){
        if(interseccion[i]!=NULL){
            cout<<interseccion[i]<<"\t";
        }
    }
    cout<<"|"<<endl;
}

//Diferencia
void differenceSet(char sets1[100],int sizes1,char sets2[100],int sizes2){
    //Crear universo
    int i,j;
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
    int i,j;
    char k;
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
    int opt,optSet,operation;

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
                    unionSet(set1,size1,set2,size2);
                    break;
                case 2://Interseccion
                    intersectionSet(set1,size1,set2,size2);
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
