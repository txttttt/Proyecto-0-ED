/* Clase creada por Kevin Jimenez Escalante y Fabian Solis Izaguirre
Esta clase se encarga de controlar varios aspectos como los tipos de usuarios.

agregar o eliminar elementos de listas de tipos de usuario, areas disponibles, ventanillas y servicios disponibles.
Si se borra un tipo de usuario o servicio se eliminan todos los tiquetes.
Si se borra un area se eliminan todos los servicios y las ventanillas.
Dar un mensaje de advertencia y solicitar confirmacion antes de borrar.

Se da uso de la libreria time para calcular la cantidad de tiempo que tarda en atenderse un ticket.
time_t es para declarar que se van a usar timestamps y time es para hacer uno con el tempo actual.

Informacion general: https://en.cppreference.com/w/cpp/chrono/c/ctime
Crear timestamp con tiempo actual: https://www.w3schools.com/cpp/cpp_date.asp
*/

#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>

#include "LinkedPriorityQueue.h"
#include "ArrayList.h"
#include "KVPair.h"

#include "Area.h"
#include "Ticket.h"
#include "Service.h"

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;
using std::cin;
using std::time;
using std::time_t;
using std::to_string;

class AdmSystem
{
private:
	List<KVPair<string, int>>* types;	// Lista de tipos de usuario
	List<Ticket>* tickets;				// Lista de tiquetes
	List<Service>* services;			// Lista de servicios
	List<Area>* areas;					// Lista de áreas en el sistemaeas en el sistema
	int ticketCounter;					// Cuenta de tiquetes

public:
	AdmSystem() {
		tickets = new ArrayList<Ticket>();				// Lista de tiquetes
		services = new ArrayList<Service>();			// Lista de servicios
		types = new ArrayList<KVPair<string, int>>();	// Lista de tipos de usuarios
		areas = new ArrayList<Area>();					// Lista de áreas en el sistema
		ticketCounter = 100;
	}

	~AdmSystem() {
		delete services;
		delete tickets;
		delete types;
		delete areas;
	}

	/*
	* Agrega una nueva área al sistema
	* @param description Hilera con la descripción del área
	* @param code Hilera con el código del área
	* @param numCounter Entero que indica la cantidad de ventanillas
	*/
	void addArea(string description, string code, int numCounter) {
		Area* newArea = new Area(description, code, numCounter);
		areas->append(*newArea);
	}

	/*
	* Elimina un área dentro del sistema
	* @param desc Hilera con la descripción del área a eliminar
	*/
	void deleteArea(string desc) {
		for (int i = 0; i < areas->getSize(); i++) {
			areas->goToPos(i);
			if (areas->getElement().getDescription() == desc)
				areas->remove();
		}
	}

	/*
	* Muestra todas las áreas añadidas
	*/
	void printAreas() {
		if (areas->getSize() == 0) {
			cout << "No hay areas registradas." << endl;
		}
		else {
			cout << "Lista de Areas:" << endl;
			for (int i = 0; i < areas->getSize(); i++) {
				areas->goToPos(i);
				Area areaSelected = areas->getElement();
				cout << areaSelected.getDescription() << ", " << areaSelected.getCode() << ", " << areaSelected.getNumCounter() << '\n';
			}
		}
	}

	/*
	* Muestra las ventanillas presentes en un área
	* @param areaCode Hilera del código del área a seleccionar
	*/
	void printCountersByArea(string areaCode) {
		for (int i = 0; i < areas->getSize(); i++) {
			areas->goToPos(i);
			if (areas->getElement().getCode() == areaCode) {
				areas->getElement().printCounters();
				return;
			}
		}
		cout << "Area no encontrada." << endl;
	}


	/*
	* Agrega un nuevo tipo de cliente al sistema
	* @param description Hilera con una descripción para el tipo de cliente
	* @param priority Entero que representa la prioridad
	* Da un mensaje de advertencia para cuando el usuario intenta usar addtype para uno ya existente
	*/
	void addType(string description, int priority) {
		KVPair<string, int> pair = KVPair<string, int>(description, priority);
		if (types->getSize() == 0) {
			types->append(pair);
		}
		else if (!types->contains(pair)) {
			types->append(pair);
		}
		else {
			cout << "El tipo de usuario ya existe." << endl;
		}
	}

	/*
	* Elimina un tipo de cliente en el sistema
	* @param description Hilera con una descripción para el tipo de cliente
	* Despliega en pantalla advertencias al eliminar un tipo  y confirmacion de la eliminacion
	* Despliega un mensaje si no encuentra el tipo a eliminar
	*/
	void deleteType(string description) {
		setlocale(LC_ALL, "");
		for (int i = 0; i < types->getSize(); i++) {
			types->goToPos(i);
			KVPair<string, int> pair = types->getElement();
			string desc = pair.getKey();
			if (desc == description) {
				char confirm;
				do {
					cout << "¿Esta seguro de que desea eliminar el tipo de usuario " << description << "? (s/n): ";
					cin >> confirm;
				} while (confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N');
				if (confirm == 's' || confirm == 'S') {
					types->remove();
					cout << "Tipo de usuario eliminado." << endl;
				}
				else {
					cout << "Eliminacion cancelada." << endl;
				}
				return;
			}
		}
		cout << "Tipo de usuario no encontrado." << endl;
	}

	/*
	* Método para imprimir la lista de types
	* llama al metodo print de arraylist
	*/
	void printTypes() {
		if (types->getSize() == 0) {
			cout << "No hay tipos de usuario registrados." << endl;
		}
		else {
			cout << "Lista de Tipos:" << endl;
			for (int i = 0; i < types->getSize(); i++) {
				types->goToPos(i);
				KVPair<string, int> typeSelected = types->getElement();
				cout << typeSelected.key << '\n';
			}
		}
	}

	/*
	* Agrega un nuevo tiquete en el sistema
	* @param code Hilera que representa el código del tiquete a agregar
	* @param hour Flotante que indica la hora en que se generó el tiquete
	* @param finalPriority Entero que representa la prioridad
	* Despliega un mensaje si el tiquete ya existe
	*/
	void addTicket(string areaCode, string userType, string serviceDescription) {
		// Buscar prioridad del tipo de usuario
		int userPriority = -1;
		for (int i = 0; i < types->getSize(); i++) {
			types->goToPos(i);
			if (types->getElement().getKey() == userType) {
				userPriority = types->getElement().getValue();
				break;
			}
		}
		if (userPriority == -1) {
			cout << "Tipo de usuario no encontrado." << endl;
			return;
		}

		// Buscar prioridad del servicio
		int servicePriority = -1;
		for (int i = 0; i < services->getSize(); i++) {
			services->goToPos(i);
			if (services->getElement().getDescription() == serviceDescription) {
				servicePriority = services->getElement().getPriority();
				break;
			}
		}
		if (servicePriority == -1) {
			cout << "Servicio no encontrado." << endl;
			return;
		}

		// Calcular `finalPriority`
		int finalPriority = userPriority * 10 + servicePriority;

		// Generar código único del tiquete
		string code = areaCode + to_string(ticketCounter);

		// Crear y agregar el tiquete
		Ticket ticket = Ticket(code, finalPriority);
		if (tickets->getSize() == 0) {
			tickets->append(ticket);
			ticketCounter++;
			cout << "Tiquete generado: " << ticket << endl;
		}
		else if (!tickets->contains(ticket)) {
			tickets->append(ticket);
			ticketCounter++; // Incrementa el contador global
			cout << "Tiquete generado: " << ticket << endl;
		}
		else {
			cout << "El tiquete ya existe." << endl;
		}
	}

	/*
	* Elimina un tiquete en el sistema
	* @param code Hilera que representa código del tiquete a eliminar
	* Despliega un mensaje de confirmacion al eliminar un tiquete
	* Despliega un mensaje si no encuentra el tiquete a eliminar
	*/
	void deleteTicket(string code) {
		for (int i = 0; i < tickets->getSize(); i++) {
			tickets->goToPos(i);
			if (tickets->getElement().getCode() == code) {
				char confirm;
				do {
					cout << "¿Esta seguro de que desea eliminar el tiquete " << code << "? (s/n): ";
					cin >> confirm;
				} while (confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N');

				if (confirm == 's' || confirm == 'S') {
					tickets->remove();
					cout << "Tiquete eliminado." << endl;
				}
				else {
					cout << "Eliminacion cancelada." << endl;
				}
				return;
			}
		}
		cout << "Tiquete no encontrado." << endl;
	}

	// Método para imprimir la lista de Tickets
	// LLama al metodo print de arraylist
	void printTickets() {
		if (tickets->getSize() == 0) {
			cout << "No hay tiquetes registrados." << endl;
		}
		else {
			cout << "Lista de Tiquetes:" << endl;
			tickets->print();
		}
	}


	/*
	* Agrega un nuevo servicio al sistema
	* @param descripction Hilera con la descripción del servicio a agregar
	* @param area Hilera que indica el área en donde el servicio tiene que localizarse
	* @param priority Entero que representa la prioridad del servicio
	*/
	void addService(string description, string area, int priority) {
		Service service = Service(description, area, priority);
		for (int i = 0; i < services->getSize(); i++) {
			services->goToPos(i);
			if ((services->getElement()).getDescription() == description) {
				cout << "El servicio ya existe." << endl;
				return;
			}
		}
		services->append(service);
	}


	/*
	* Elimina un servicio dentro del sistema
	* @param description Hilera con la descripción del servicio a eliminar
	*/
	void deleteService(string description) {
		for (int i = 0; i < services->getSize(); i++) {
			services->goToPos(i);
			if (services->getElement().getDescription() == description) {
				char confirm;
				do {
					cout << "¿Esta seguro de que desea eliminar el servicio " << description << "? (s/n): ";
					cin >> confirm;
				} while (confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N');

				if (confirm == 's' || confirm == 'S') {
					services->remove();
					tickets->clear();
					cout << "Servicio eliminado." << endl;
				}
				else {
					cout << "Eliminacion cancelada." << endl;
				}
				return;
			}
		}
		cout << "Servicio no encontrado." << endl;
	}


	// Muestra la lista de servicios
	// Llama al método print de ArrayList
	void printServices() {
		if (services->getSize() == 0) {
			cout << "No hay servicios registrados.\n";
		}
		else {
			cout << "Lista de Servicios:\n";
			for (int i = 0; i < services->getSize(); i++) {
				services->goToPos(i);
				Service serviceSelected = services->getElement();
				cout << serviceSelected.getDescription() << '\n';
			}
		}
	}

	/*
	* Atiende el tiquete de mayor prioridad de un área 
	* @param code Hilera con el código del área a atender el tiquete
	*/
	void attendTicket(string code) {
		for (int i = 0; i < areas->getSize(); i++) {
			if (areas->getElement().getCode() == code)
				areas->getElement().attendNextTicket();
		}
	}

	/*
	* Muestra estadísticas de los tiquetes generados, según por área, servicio y tipo de usuario
	*/
	void printStatistics() {
		cout << "Cantidad de tiquetes por servicio: \n";

	}

	/*
	* Limpia todos los tiquetes que se encuentren en cada área presente en el sistema
	*/
	void clearAreas() {
		areas->goToStart();
		for (int i = 0; i < areas->getSize(); i++) {
			areas->getElement().deleteTickets();
			areas->goToPos(i);
		}
	}

	//Solicitud de un tiquete

	//Ventanilla tiene a tiquete

	// Administracion del sistema

	// Consulta de estadisticas
};