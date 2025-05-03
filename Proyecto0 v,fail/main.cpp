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

// para funciones que reciben varios parametros
int opcion;
string input;
string input2;
string input3;
AdmSystem* control = new AdmSystem();


// ESTADO COLAS
//-------------------------------------------------------------------------------------------------
void static estadoColas() {
    control->printAreas();
}

// TIQUETES
//-------------------------------------------------------------------------------------------------
void static tiquetes() {
    getStr("Inserte el área: ", input);
    getStr("Inserte el tipo de usuario: ", input2);
    getStr("Inserte la decripcion del servicio: ", input3);
    control->addTicket(input, input2, input3);
}

// ATENDER
//-------------------------------------------------------------------------------------------------
void static atender() {
    getStr("Inserte el codigo de area: ", input);
    control->attendTicket(input);
}

// ADMINISTRACION
//-------------------------------------------------------------------------------------------------
void static tiposUsuario() {
    while (true) {
        control->printTypes();
        getInt(users_options, opcion);
        switch (opcion) {
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
            return;
        default:
            cout << "La opcion no existe\n";
            break;
        }
    }
}

void static areas() {
    while (true) {
        control->printAreas();
        getInt(areas_options, opcion);
        switch (opcion) {
        case 0:
            getStr("Inserte la descripcion: ", input);
            getStr("Inserte el codigo: ", input);
            getInt("Inserte la prioridad: ", opcion);
            control->addArea(input, input2, opcion);
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
}

void static servicios() {
    while (true) {
        control->printServices();
        cout << "Para crear un nuevo servicio hay que tener al menos un area creada";
        getInt(services_options, opcion);
        switch (opcion) {
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
            return;
        default:
            cout << "La opcion no existe\n";
            break;
        }
    }
}

void static vaciarColas() {
    control->clearAreas();
}

void static administracion() {
    while (true) {
        getInt(admin_menu, opcion);
        switch (opcion) {
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
            return;
        default:
            cout << "La opcion no existe\n";
            break;
        }
    }
}

// ESTADISTICAS
//-------------------------------------------------------------------------------------------------
void static estadisticas() {
    control->printStatistics();
}

// MAIN
//-------------------------------------------------------------------------------------------------
int main() {
    setlocale(LC_ALL, "");

    // Setup inicial
    control->addType("Regular", 2);
    control->addType("Adulto mayor", 0);
    control->printTypes();

    control->addService("Deposito", "CJ", 2);
    control->addService("Retiro", "CJ", 0);
    control->printServices();

    control->addArea("Cajas", "CJ", 4);
    control->addArea("Consultas", "CO", 5);
    control->printAreas();

    while (true) {
        try {
            getInt(main_menu, opcion);
            switch (opcion) {
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