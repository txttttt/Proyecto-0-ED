/* Archivo creado por: Javier Lee Liang
* Fecha creada: 27/04/2025
* El archivo contiene métodos para mostrar el menú para el usario y también
* recibir entrada de parte del usuario a través de la terminal
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include "Header.h"

using std::cout;
using std::cin;
using std::runtime_error;
using std::string;

string const main_menu =
"\nMenú principal\n"
"---------------------------------\n"
"0. Estado de las colas\n"
"1. Tiquetes\n"
"2. Atender\n"
"3. Administración\n"
"4. Estadísticas del sistema\n"
"5. Salir\n"
"---------------------------------\n"
"Seleccione alguna de las acciones: ";

string const ticket_menu = 
"\nMenú de tiquetes\n"
"---------------------------------\n"
"0. Seleccionar tipo de cliente y servicio\n"
"1. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las acciones: ";

string const admin_menu = 
"\nMenú de administración\n"
"---------------------------------\n"
"0. Tipos de usuario\n"
"1. Áreas\n"
"2. Servicios disponibles\n"
"3. Limpiar colas y estadísticas\n"
"4. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones a modificar: ";

string const users_options =
"\nOpciones de usuarios\n"
"---------------------------------\n"
"0. Agregar\n"
"1. Eliminar\n"
"2. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones: ";

string const areas_options =
"\nOpciones de áreas\n"
"---------------------------------\n"
"0. Agregar\n"
"1. Modificar cantdad de ventanillas\n"
"2. Eliminar\n"
"3. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones: ";

string const services_options =
"\nOpciones de servicios\n"
"---------------------------------\n"
"0. Agregar\n"
"1. Eliminar\n"
"2. Reordernar\n"
"3. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones: ";

/* Creado por Javier Lee Liang
* Realiza un while loop y dentro de este tiene un try catch para correr una función
* @param void (*f)(bool&, int&) Puntero a una función que retorna void y de entradas tiene una referencia a un boolano
* una referencia a un entero
* 
* Fuente de cómo aprendí a hacer esto: https://www.geeksforgeeks.org/passing-a-function-as-a-parameter-in-cpp/
*/
void runningLoop(void (*f)(bool&, int&)) {
	bool running = true;
	int input;
	while (running) {
		try {
			f(running, input);
		}
		catch (const runtime_error& e) {
			cout << e.what() << '\n';
		}
	}
}

void getTicket(bool& running, int& input) {}

/* Creado por Javier Lee Liang
* Muestra el menú de tiquetes y recibe un entero de parte del usuario que indica la acción a realizar
*/
void getTicketAction(bool& running, int& input) {
	getInt(ticket_menu, input);
	switch (input) {
	case 0:
		
		break;
	case 1:
		running = false;
		break;
	}
}

/* Creado por Javier Lee Liang
* Muestra el menú de usuarios y recibe un entero de parte del usuario que indica la acción a realizar
*/
void getUsersAction(bool& running, int& input) {
	getInt(users_options, input);
	switch (input) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		running = false;
		break;
	}
}

/* Creado por Javier Lee Liang
* Muestra el menú de áreas y recibe un entero de parte del usuario que indica la acción a realizar
*/
void getAreasAction(bool& running, int& input) {
	getInt(areas_options, input);
	switch (input) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		running = false;
		break;
	}
}

/* Creado por Javier Lee Liang
* Muestra el menú de áreas y recibe un entero de parte del usuario que indica la acción a realizar
*/
void getServicesAction(bool& running, int& input) {
	getInt(services_options, input);
	switch (input) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		running = false;
		break;
	}
}

/* Creado por Javier Lee Liang
* Muestra el menú de administración y recibe un entero de parte del usuario que indica la acción a realizar
*/
void getAdminAction(bool& running, int& input) {
	getInt(admin_menu, input);
	switch (input) {
	case 0:
		runningLoop(&getUsersAction);
		break;
	case 1:
		runningLoop(&getAreasAction);
		break;
	case 2:
		runningLoop(&getServicesAction);
		break;
	case 3:
		break;
	case 4:
		running = false;
		break;
	}
}

/* Creado por Javier Lee Liang
* Muestra el menú principal y recibe un entero de parte del usuario que indica la acción a realizar 
* una accion dentro del programa
* @param running Referencia a una variable booleana creada indicando si el programa está corriendo o no
*/
void getMenuAction(bool& running, int& input) {
	getInt(main_menu, input);
	switch (input) {
	case 0:
		break;
	case 1:
		runningLoop(&getTicketAction);
		break;
	case 2:
		break;
	case 3:
		runningLoop(&getAdminAction);
		break;
	case 4:
		break;
	case 5:
		running = false;
		break;
	}
}
	