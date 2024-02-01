/****PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO
FECHA: 29 de Enero de 2024
PROGRAMA: specialChar.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Un programa que utiliza secuencias de escape y cadenas de control de tipo de dato para tratar entradas de datos.
*****************************************************************************************/

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
    float num;
    int num2;
    string word;

    printf("Ingrese un numero decimal.\n");
    scanf("%f",&num);
    printf("Expresado en base y exponente: %e \t Expresado en real: %g\n",num,num);
    
    printf("Ingrese un numero entero.\n");
    scanf("%d",&num2);
    printf("Expresado en hexadecimal: %x\vExpresado en octal: %o\n",num2,num2);

    printf("Son correctos\x3F. Pero por supuesto que si.\n");
    printf("\a\n");

    cout<<"Ingrese una palabra."<<endl;
    scanf("%s",word);
    printf("\"%s\"",word);
}