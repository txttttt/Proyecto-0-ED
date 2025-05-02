/* Archivo creado por Javier Lee Liang
* Este es el archivo principal en donde se va a correr el proyecto
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include "DLinkedList.h"
#include "KVPair.h"

#include "OrderedArrayList.h"
#include "Service.h"
#include "AdmSystem.h"
#include "Area.h"
#include "Counter.h"
#include "Ticket.h"
#include "Header.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::runtime_error;
int opcion;
// para funciones que reciben varios parametros
string input;
string input2;
AdmSystem* control = new AdmSystem();


// ESTADO COLAS
//-------------------------------------------------------------------------------------------------
void estadoColas() {
    // poner prints directamente
}
// TIQUETES
//-------------------------------------------------------------------------------------------------
void tiquetes() {
    cout << "Seleccione el tipo de usuario que es: ";

}
// ATENDER
//-------------------------------------------------------------------------------------------------
void atender() {
    getStr("Inserte el codigo de area: ", input);
    getInt("Inserte el numero de ventanilla", opcion);

}
// ADMINISTRACION
//-------------------------------------------------------------------------------------------------
void tiposUsuario() {
    cout << users_options;
    getInt("", opcion);
    switch (opcion)
    {
    case 0:
        getStr("Inserte la descripcion: ", input);
        getInt("Inserte la prioridad: ", opcion);
        control->addType(input, opcion);
        break;
    case 1:
        getStr("Inserte de descripcion: ", input);
        control->deleteType(input);
        break;
    case 2:
        break;
    default:
        cout << "La opcion no existe\n";
        break;
    }
}

void areas() {
    cout << users_options;
    getInt("", opcion);
    switch (opcion)
    {
    case 0:
        getStr("Inserte la descripcion: ", input);
        getStr("Inserte el codigo: ", input);
        getInt("Inserte la prioridad: ", opcion);
        control->addArea(input, input2 ,opcion);
        break;
    case 1:
        getStr("Inserte la descripcion: ", input);
        control->deleteArea(input);
        break;
    case 2:
        break;
    default:
        cout << "La opcion no existe\n";
        break;
    }
}

void servicios() {
    cout << users_options;
    getInt("", opcion);
    switch (opcion)
    {
    case 0:
        getStr("Inserte de descripcion: ", input);
        getStr("Inserte el area: ", input2);
        getInt("Inserte la prioridad: ", opcion);
        control->addService(input, input2, opcion);
        break;
    case 1:
        getStr("Inserte de descripcion: ", input);
        control->deleteService(input);
        break;
    case 2:
        break;
    default:
        cout << "La opcion no existe\n";
        break;
    }
}

void vaciarColas() {
    cout << users_options;
    getInt("", opcion);
    switch (opcion)
    {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    default:
        cout << "La opcion no existe\n";
        break;
    }
}

void administracion() {
    cout << admin_menu;
    getInt("", opcion);
    switch (opcion)
    {
    case 0:
        tiposUsuario();
        break;
    case 1:
        areas();
        break;
    case 2:
        servicios();
        break;
    case 3:
        vaciarColas();
        break;
    case 4:
        break;
    default:
        cout << "La opcion no existe\n";
        break;
    }
}



// ESTADISTICAS
//-------------------------------------------------------------------------------------------------
void estadisticas() {
    // poner prints directamente
}

// MAIN
//-------------------------------------------------------------------------------------------------
int main() {
while (true) {
try {
    cout << main_menu;
    getInt("", opcion);
    switch (opcion)
    {
    case 0:
        estadoColas();
        break;
    case 1:
        tiquetes();
        break;
    case 2:
        atender();
        break;
    case 3:
        administracion();
        break;
    case 4:
        estadisticas();
        break;
    case 5:
        return 0;
    default:
        cout << "La opcion no existe\n";
        break;
    }
}
catch (const runtime_error& e) {
    cout << "Error: " << e.what() << endl;
}
}
}
