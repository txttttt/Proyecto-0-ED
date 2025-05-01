/* Clase creada por Kevin Jimenez Escalante y Fabian Solis Izaguirre
* Esta clase se encarga de controlar varios aspectos como los tipos de usuarios

agregar o eliminar elementos de listas de tipos de usuario, areas disponibles, ventanillas y servicios disponibles.
Si se borra un tipo de usuario o servicio se eliminan todos los tiquetes.
Si se borra un area se eliminan todos los servicios y las ventanillas
Dar un mensaje de advertencia y solicitar confirmacion antes de borrar.
*/

#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "LinkedPriorityQueue.h"
#include "ArrayList.h"
#include "KVPair.h"
#include "Ticket.h"
#include "Service.h"

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;
using std::cin;

class AdmSystem
{
private:
	List<KVPair<string, int>>* types;
	List<Ticket>* tickets;
	List<Service>* services;

public:
	AdmSystem() {
		tickets = new ArrayList<Ticket>();
		services = new ArrayList<Service>();
		types = new ArrayList<KVPair<string, int>>();
	}

	~AdmSystem() {
		delete services;
		delete tickets;
		delete types;
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
		for (int i = 0; i < types->getSize(); i++) {
			types->goToPos(i);
			KVPair<string, int> pair = types->getElement();
			string desc = pair.getKey();
			if (desc == description) {
				char confirm;
				do {
					cout << "¿Está seguro de que desea eliminar el tipo de usuario " << description << "? (s/n): ";
					cin >> confirm;
				} while (confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N');
				if (confirm == 's' || confirm == 'S') {
					types->remove();
					cout << "Tipo de usuario eliminado." << endl;
				}
				else {
					cout << "Eliminación cancelada." << endl;
				}
				return;
			}
		}
		cout << "Tipo de usuario no encontrado." << endl;
	}

	/*Método para imprimir la lista de types
	* llama al metodo print de arraylist
	*/
	void printTypes() {
		if (types->getSize() == 0) {
			cout << "No hay tipos de usuario registrados." << endl;
		}
		else {
			cout << "Lista de Tipos:" << endl;
			types->print();
		}
	}

	/*
	* Agrega un nuevo tiquete en el sistema
	* @param code Hilera que representa el código del tiquete a agregar
	* @param hour Flotante que indica la hora en que se generó el tiquete
	* @param finalPriority Entero que representa la prioridad
	* Despliega un mensaje si el tiquete ya existe
	*/
	void addTicket(string code, float hour, int finalPriority) {
		Ticket ticket = Ticket(code, hour, finalPriority);
		if (tickets->getSize() == 0)
			tickets->append(ticket);
		else if (!tickets->contains(ticket))
			tickets->append(ticket);
		else
			cout << "El tiquete ya existe." << endl;
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
					cout << "¿Está seguro de que desea eliminar el tiquete " << code << "? (s/n): ";
					cin >> confirm;
				} while (confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N');

				if (confirm == 's' || confirm == 'S') {
					tickets->remove();
					cout << "Tiquete eliminado." << endl;
				}
				else {
					cout << "Eliminación cancelada." << endl;
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


	// Método para imprimir la lista de servicios
	// Llama al método print de ArrayList
	void printServices() {
		if (services->getSize() == 0) {
			cout << "No hay servicios registrados." << endl;
		}
		else {
			cout << "Lista de Servicios:" << endl;
			services->print();
		}
	}

	/*
	* Genera un entero según el tipo de cliente y el servicio que el cliente posee
	* @param userPriority Entero indicando la prioridad del tipo de cliente
	* @param servicePriority Entero indicando la prioridad del servicio
	* @ret Entero con el indicando la prioridad de un cliente según su tipo y servicio
	*/
	int formula(int userPriority, int servicePriority) {
		return userPriority * 10 + servicePriority;
	}

	//Solicitud de un tiquete

	//Ventanilla tiene a tiquete

	// Administracion del sistema

	// Consulta de estadisticas
};
