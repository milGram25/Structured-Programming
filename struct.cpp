#include <iostream>

using namespace std;

struct Tficha{
    char nombre [30], apellido[30], ciudad[30], estado[30], municipio[30], calle[30];
    int edad;
    float estatura;
};

void trabajoFicha(struct Tficha ficha){
    cout<<"Ingrese el nombre/nombres"<<endl;
    cin.getline(ficha.nombre,30,'\n');
    cout<<"Ingrese apellidos"<<endl;
    cin.getline(ficha.apellido,30,'\n');
    cout<<"Ingrese la ciudad"<<endl;
    cin.getline(ficha.ciudad,30,'\n');
    cout<<"Ingrese el estado"<<endl;
    cin.getline(ficha.estado,30,'\n');
    cout<<"Ingrese el municipio"<<endl;
    cin.getline(ficha.municipio,30,'\n');
    cout<<"Ingrese la calle"<<endl;
    cin.getline(ficha.calle,30,'\n');
    cout<<"Ingrese la edad"<<endl;
    cin>>ficha.edad;
    cout<<"Ingrese la estatura en cm"<<endl;
    cin>>ficha.estatura;
}

void mostrarFicha(struct Tficha ficha){
    cout<<ficha.nombre<<endl;
    cout<<ficha.apellido<<endl;
    cout<<ficha.ciudad<<endl;
    cout<<ficha.estado<<endl;
    cout<<ficha.municipio<<endl;
    cout<<ficha.calle<<endl;
    cout<<ficha.edad<<endl;
    cout<<ficha.estatura<<endl;
}

int main(){
    struct Tficha f1,f2,f3,f4,f5;
    
    int fich;
    cout<<"Cual ficha desea editar?"<<endl;
    cin>>fich;
    switch(fich){
        case 1:
            trabajoFicha(f1);
            mostrarFicha(f1);
            break;
        case 2:
            trabajoFicha(f2);
            break;
        case 3:
            trabajoFicha(f3);
            break;
        case 4:
            trabajoFicha(f4);
            break;
        case 5:
            trabajoFicha(f5);
            break;
    }


}