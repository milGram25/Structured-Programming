/*********PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 24 de abril de 2024
PROGRAMA: arrays_v2.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Tratar los datos dentro de un arreglo de tamaño 50, ordenarlos y buscarlos.
**************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int i,j;

void emptyArr(int arr[]){
    for(i=0;i<50;i++){
        arr[i]=NULL;
    }
}

void addData(int arr[]){
    int sum,times;
    bool valid=false;
    cout<<"Cuantos datos desea ingresar?"<<endl;
    cin>>times;
    sum=0;
    for(i=0;i<50;i++){
        if(arr[i]==NULL){
            sum++;
        }
    }
    if(sum<times){
        cout<<"No hay suficientes espacios vacios."<<endl;
    } else {
    for(i=0;i<times;i++){
        for(j=0;j<50;j++){
            if(arr[j]==NULL){
                cout<<"Ingrese valor entre 0 y 200. Se anadira en la posicion "<<j+1<<endl;
                do{
                    cin>>arr[j];
                    if(arr[j]>=0 && arr[j]<=200){
                        valid=true;
                    } else {
                        cout<<"Valor fuera de rango. Ingrese nuevo valor."<<endl;
                        arr[j]=NULL;
                    }
                } while (!valid);
                j=50;
            }
        }
    }
    }
}

void randomFill(int arr[]){
    for(i=0;i<50;i++){
        if(arr[i]==NULL){
            arr[i]=(rand()%200)+1;
        }
    }
    cout<<"Llenado completado."<<endl;
}

void showArr(int arr[],int index, int lines){
    if(lines==5){
        return;
    }

    int count=0;

    
}

void MostrarArregloRecursivo(int arr[], int index, int elements, int row) {
    if (row == 5) { // Si ya hemos impreso todas las filas necesarias, terminamos la recursión
        return;
    }
    int count=0;
    for(i=0;i<50;i++){
        if(arr[i]!=NULL){
            count++;
        }
    }
    if (index < count) { // Si aún quedan elementos por mostrar
        cout << arr[index] << "\t"; // Mostramos el elemento actual

        if ((index + 1) % elements == 0) { // Si hemos impreso la cantidad de elementos por fila
            cout << endl; // Cambiamos de línea
            MostrarArregloRecursivo(arr, index + 1, elements, row + 1); // Llamamos recursivamente para la siguiente fila
        } else { // Si aún quedan elementos por mostrar en la fila actual
            MostrarArregloRecursivo(arr, index + 1, elements, row); // Llamamos recursivamente para el siguiente elemento de la misma fila
        }
    }
}

void showArr(int arr[]) {
    cout << "Datos en el arreglo:" << endl;
    MostrarArregloRecursivo(arr, 0, 10, 0); // Llamamos a la función recursiva con el índice inicial, 10 elementos por fila y fila inicial 0
   cout<<endl;
}
void sumArr(int arr[]){
    int sum=0;
    for(i=0;i<50;i++){
        sum=sum+arr[i];
    }
    cout<<"La suma de los elementos es: "<<sum<<endl;
}

void editArr(int arr[]){
    int pos,edit;
    char confirm;
    cout<<"Que posicion de elemento desea editar."<<endl;
    cin>>pos;
    cout<<"Que desea hacer?\n1. Modificar valor\n2. Eliminar valor"<<endl;
    cin>>edit;
    switch(edit){
        case 1:
            //Modificar valor
            cout<<"Ingrese valor nuevo."<<endl;
            cin>>arr[pos-1];
            break;
        case 2:
            //Eliminar  valor
            cout<<"Para confirmar ingrese \"Y\""<<endl;
            cin>>confirm;
            if(confirm=='Y'){
                arr[pos-1]=NULL;
                cout<<"Valor eliminado."<<endl;
            } else {
                cout<<"Eliminado cancelado."<<endl;
            }
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            break;
        }
}

void bubbleSort(int arr[]){
    bool flag;
    int back;
    do{
        flag=true;
        for(i=0;i<49;i++){
            if(arr[i]>arr[i+1]){
                back=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=back;
                flag=false;
            }
        }
    } while (!flag);
}

void OrdenarQuick(int arr[], int izquierda, int derecha) {
    int i = izquierda, j = derecha;
    int pivote = arr[(izquierda + derecha) / 2]; // Selecciona el pivote como el elemento central

    // Partición
    while (i<=j) {
        while (arr[i]<pivote) i++;
        while (arr[j]>pivote) j--;
        if (i<=j) {
            // Intercambio
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }

    // Llamadas recursivas para ordenar las particiones restantes
    if (izquierda<j) OrdenarQuick(arr, izquierda, j);
    if (i<derecha) OrdenarQuick(arr, i, derecha);
}

void binarySearch(int arr[],int min,int max,int search){
    if(min>=max){
        cout<<"Valor no encontrado"<<endl;
        return;
    }
    int pivot=(min+max)/2;
    if(arr[pivot]==search){
        cout<<"Valor ubicado en la posicion: "<<pivot+1<<endl;
    } else if(arr[pivot]<search){
        //Valor mayor a pivote
        binarySearch(arr,pivot+1,max,search);
    } else {
        //Valor menor a pivote
        binarySearch(arr,min,pivot+1,search);
    }
}

int main(){
    int opt,searching,sort;
    int numbers[50];
    bool exit=false;
    //Inicializar el arreglo
    emptyArr(numbers);
    //Iniciar randomizador
    srand(time(NULL));
    do{
        //Menu
        cout<<"Elija la opcion deseada.\n1. Anadir valores al arreglo\n2. Mostrar lista de valores\n3. Mostrar suma de valores\n4. Editar elemento\n5. Vaciar arreglo\n6. Llenado de valores aleatorios\n7. Ordenado y Busqueda\n8. Finalizar"<<endl;
        cin>>opt;
        switch(opt){
            case 1:
                //Añadir valores en campos vacíos
                addData(numbers);
                break;
            case 2:
                //Imprimir arreglo
                showArr(numbers);
                break;
            case 3:
                //Sumar arreglo
                sumArr(numbers);
                break;
            case 4:
                //Editar elemento
                editArr(numbers);
                break;
            case 5:
                //Vaciar arreglo
                emptyArr(numbers);
                break;
            case 6:
                randomFill(numbers);
                break;                
            case 7:
                //Ordenado y Búsqueda
                cout<<"Que metodo de ordenado desea utilizar?\n1. Burbuja\n2. QuickSort"<<endl;
                cin>>sort;
                switch(sort){
                    case 1:
                        //Burbuja
                        bubbleSort(numbers);
                        break;
                    case 2:
                        //QuickSort
                        OrdenarQuick(numbers,0,49);
                        break;
                }
                cout<<"Que elemento desea buscar?"<<endl;
                cin>>searching;
                binarySearch(numbers,0,49,searching);
                break;
            case 8:
                //Finalizar programa
                exit=true;
                break;
        }
    } while (!exit);
}