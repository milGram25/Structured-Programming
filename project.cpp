/*********PRESENTACIÓN********
NOMBRE: MILTON GARCÍA ROMO y CHRISTOPHER SANTANA
FECHA: 18 de mayo de 2024
PROGRAMA: project.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: CARLOS JAVIER CRUZ FRANCO
DESCRIPCIÓN: Un programa que permite editar y almacenar la información académica de hasta 5 alumnos.
**************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits>

using namespace std;

//registrar alumno, maestro, materia, carrera, calificación
/*calificación con
59 reprobado
60-79 regular
80-89 Muy bien
90-100 excelente
debe borrar y editar los datos*/

struct ficha {
    string nombre;
    string carrera;
    int codigo;
    float promedio;
};

struct materia {
    string nombrem;
    string profe;
    float calificacion;
};

FILE *fichero;

string nivel(int cal) {
    if (cal == 100) {
        return "Excelente";
    } else if (cal <= 99 && cal >= 90) {
        return "Muy Bueno";
    } else if (cal <= 89 && cal >= 80) {
        return "Bueno";
    } else if (cal <= 79 && cal >= 70) {
        return "Regular";
    } else if (cal <= 69 && cal >= 60) {
        return "Malo";
    } else if (cal <= 59 && cal >= 0) {
        return "Reprobado";
    } else {
        return "Calificacion no valida";
    }
}

void elegirAlumnoEditar(){
    int opAlum;
    cout<<"Elija un alumno a editar.\n1. Alumno 1\n2. Alumno 2\n3. Alumno 3\n4. Alumno 4\n5. Alumno 5"<<endl;
    cin>>opAlum;
    switch(opAlum){
        case 1:
            fichero = fopen("Alumno1.txt","wt");
            break;
        case 2:
            fichero = fopen("Alumno2.txt","wt");
            break;
        case 3:
            fichero = fopen("Alumno3.txt","wt");
            break;
        case 4:
            fichero = fopen("Alumno4.txt","wt");
            break;
        case 5:
            fichero = fopen("Alumno5.txt","wt");
            break;
    }
    if (fichero == NULL) {
        printf("ERROR: No se pudo abrir el archivo\n");
    }
}

void elegirAlumnoLeer(){
    int opAlum;
    cout<<"Que alumno desea mostrar?\n1. Alumno 1\n2. Alumno 2\n3. Alumno 3\n4. Alumno 4\n5. Alumno 5"<<endl;
    cin>>opAlum;
    switch(opAlum){
        case 1:
            fichero = fopen("Alumno1.txt","rt");
            break;
        case 2:
            fichero = fopen("Alumno2.txt","rt");
            break;
        case 3:
            fichero = fopen("Alumno3.txt","rt");
            break;
        case 4:
            fichero = fopen("Alumno4.txt","rt");
            break;
        case 5:
            fichero = fopen("Alumno5.txt","rt");
            break;
    }
    if (fichero == NULL) {
        printf("ERROR: No se pudo abrir el archivo\n");
    }
}


int main(void) {
    int eleccion, alumno, materia;
    cout << "Escoge una opcion para realizar\n";
    cout << "1. Editar\n" << "2. Mostrar\n" << "3. Salir\n";
    cin >> eleccion;

    struct ficha alumno1;
    struct materia m1, m2, m3, m4, m5;

    do {
        switch (eleccion) {
            case 1: //Editar info del archivo
                {
                    elegirAlumnoEditar();

                    do{
                    cout << "¿Qué informacion deseas colocar?" << endl;
                    cout << "1. Nombre\n2. Carrera\n3. Codigo\n4. Las 3 anteriores\n5. Materias\n6. Salir\n";
                    cin >> alumno;

                    switch (alumno) {
                        case 1: //Solo Nombre
                            cout << "Ingrese su nombre completo\n";
                            cin.ignore();
                            getline(cin, alumno1.nombre);
                            break;

                        case 2: //Solo Carrera
                            cout << "Ingrese la Carrera Universitaria\n";
                            getline(cin, alumno1.carrera);
                            break;

                        case 3: //Solo Código
                            cout << "Ingrese el codigo de estudiante\n";
                            cin >> alumno1.codigo;
                            break;

                        case 4: //Nombre, Carrera y Código
                            cout << "Ingrese su nombre completo\n";
                            cin.ignore();
                            getline(cin, alumno1.nombre);
                            cout << "Ingrese la Carrera Universitaria\n";
                            getline(cin, alumno1.carrera);
                            cout << "Ingrese el codigo de estudiante\n";
                            cin >> alumno1.codigo;
                            break;

                        case 5: // Materias
                        do {
                            cout << "Escoja alguna opcion para el ingreso de materias\n";
                            cout << "1. Materia 1\n2. Materia 2\n3. Materia 3\n4. Materia 4\n5. Materia 5\n6. Salir\n";
                                cin >> materia;
                                cin.ignore();

                                switch (materia) {
                                    case 1: //Materia 1
                                        cout << "Primera Materia\n" << "Nombre de la Materia\n";
                                        getline(cin, m1.nombrem);
                                        cout << "Nombre del Profesor\n";
                                        getline(cin, m1.profe);
                                        do {
                                            cout << "Calificacion de la Materia" << endl;
                                            cin >> m1.calificacion;
                                            if (m1.calificacion < 0 || m1.calificacion > 100) {
                                                cout << "Calificacion no Valida\n";
                                            }
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Limpiar el búfer hasta encontrar un salto de línea
                                        } while (m1.calificacion < 0 || m1.calificacion > 100);
                                        break;

                                    case 2: //materia 2
                                        cout << "Segunda Materia\n" << "Nombre de la Materia\n";
                                        getline(cin, m2.nombrem);
                                        cout << "Nombre del Profesor\n";
                                        getline(cin, m2.profe);
                                        do {
                                            cout << "Calificacion de la Materia" << endl;
                                            cin >> m2.calificacion;
                                            if (m2.calificacion < 0 || m2.calificacion > 100) {
                                                cout << "Calificacion no Valida\n";
                                            }
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        } while (m2.calificacion < 0 || m2.calificacion > 100);
                                        break;

                                    case 3: //Materia 3
                                        cout << "Tercera Materia\n" << "Nombre de la Materia\n";
                                        getline(cin, m3.nombrem);
                                        cout << "Nombre del Profesor\n";
                                        getline(cin, m3.profe);
                                        do {
                                            cout << "Calificacion de la Materia" << endl;
                                            cin >> m3.calificacion;
                                            if (m3.calificacion < 0 || m3.calificacion > 100) {
                                                cout << "Calificacion no Valida\n";
                                            }
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        } while (m3.calificacion < 0 || m3.calificacion > 100);
                                        break;

                                    case 4: //materia 4
                                        cout << "Cuarta Materia\n" << "Nombre de la Materia\n";
                                        getline(cin, m4.nombrem);
                                        cout << "Nombre del Profesor\n";
                                        getline(cin, m4.profe);
                                        do {
                                            cout << "Calificacion de la Materia" << endl;
                                            cin >> m4.calificacion;
                                            if (m4.calificacion < 0 || m4.calificacion > 100) {
                                                cout << "Calificacion no Valida\n";
                                            }
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        } while (m4.calificacion < 0 || m4.calificacion > 100);
                                        break;

                                    case 5: //Materia 5
                                        cout << "Quinta Materia\n" << "Nombre de la Materia\n";
                                        getline(cin, m5.nombrem);
                                        cout << "Nombre del Profesor\n";
                                        getline(cin, m5.profe);
                                        do {
                                            cout << "Calificacion de la Materia" << endl;
                                            cin >> m5.calificacion;
                                            if (m5.calificacion < 0 || m5.calificacion > 100) {
                                                cout << "Calificacion no Valida\n";
                                            }
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        } while (m5.calificacion < 0 || m5.calificacion > 100);
                                        break;
                                }
                            } while (materia != 6);


                            break;

                        case 6:
                            cout << "Saliendo de la ficha del alumno" << endl;
                            break;

                        default:
                            cout << "Opcion no valida" << endl;
                    }
                    
                    } while (alumno !=6 );

                    alumno1.promedio = (m1.calificacion + m2.calificacion + m3.calificacion + m4.calificacion + m5.calificacion) / 5;
                    fprintf(fichero, "Nombre: %s\n", alumno1.nombre.c_str());
                    fprintf(fichero, "Carrera: %s\n", alumno1.carrera.c_str());
                    fprintf(fichero, "Codigo: %d\n", alumno1.codigo);

                    fprintf(fichero, "\nNombre de la Materia: %s\n", m1.nombrem.c_str());
                    fprintf(fichero, "Profesor : %s\n", m1.profe.c_str());
                    fprintf(fichero, "Calificacion: %.2f (%s)\n", m1.calificacion, nivel(m1.calificacion).c_str());

                    fprintf(fichero, "\nNombre de la Materia: %s\n", m2.nombrem.c_str());
                    fprintf(fichero, "Profesor : %s\n", m2.profe.c_str());
                    fprintf(fichero, "Calificacion: %.2f (%s)\n", m2.calificacion, nivel(m2.calificacion).c_str());

                    fprintf(fichero, "\nNombre de la Materia: %s\n", m3.nombrem.c_str());
                    fprintf(fichero, "Profesor : %s\n", m3.profe.c_str());
                    fprintf(fichero, "Calificacion: %.2f (%s)\n", m3.calificacion, nivel(m3.calificacion).c_str());

                    fprintf(fichero, "\nNombre de la Materia: %s\n", m4.nombrem.c_str());
                    fprintf(fichero, "Profesor : %s\n", m4.profe.c_str());
                    fprintf(fichero, "Calificacion: %.2f (%s)\n", m4.calificacion, nivel(m4.calificacion).c_str());

                    fprintf(fichero, "\nNombre de la Materia: %s\n", m5.nombrem.c_str());
                    fprintf(fichero, "Profesor : %s\n", m5.profe.c_str());
                    fprintf(fichero, "Calificacion: %.2f (%s)\n", m5.calificacion, nivel(m5.calificacion).c_str());

                    fprintf(fichero, "\nPromedio: %.2f (%s)\n", alumno1.promedio, nivel(alumno1.promedio).c_str());
                }

                fclose(fichero);

                break;

            case 2: //Mostrar info del archivo
                {
                    elegirAlumnoLeer();

                    char linea[100];
                    while (fgets(linea, sizeof(linea), fichero) != NULL) {
                        cout << linea;
                    }
                }

                fclose(fichero);

                break;

            case 3:
                cout << "Saliendo del programa" << endl;
                break;

            default:
                cout << "Esa respuesta no es valida" << endl;
        }

        if (eleccion != 3) {
            cout << "Escoge una opcion para realizar\n";
            cout << "1. Editar\n" << "2. Mostrar\n" << "3. Salir\n";
            cin >> eleccion;
        }
    } while (eleccion != 3);

    return 0;
}