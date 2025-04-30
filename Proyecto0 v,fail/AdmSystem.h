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
	*/
	void addType(string description, int priority) {
		KVPair<string, int> pair = KVPair<string, int>(description, priority);
		if (types->getSize() == 0) {
			types->append(pair);
		}
		else if (!types->contains(pair)) {
			types->append(pair);
		}
	}

	/*
	* Elimina un tipo de cliente en el sistema
	* @param description Hilera con una descripción para el tipo de cliente
	*/
	void deleteType(string description) {
		for (int i = 0; i < types->getSize(); i++) {
			types->goToPos(i);
			KVPair<string, int> pair = types->getElement();
			string desc = pair.getKey();
			if (desc == description) {
				types->remove();
				tickets->clear();
			}
		}
	}

	/*
	* Agrega un nuevo tiquete en el sistema
	* @param code Hilera que representa el código del tiquete a agregar
	* @param hour Flotante que indica la hora en que se generó el tiquete
	* @param finalPriority Entero que representa la prioridad
	*/
	void addTicket(string code, float hour, int finalPriority) {
		Ticket ticket = Ticket(code, hour, finalPriority);
		if (!tickets->contains(ticket))
			tickets->append(ticket);
	}

	/*
	* Elimina un tiquete en el sistema
	* @param code Hilera que representa código del tiquete a eliminar
	*/
	void deleteTicket(string code) {
		for (int i = 0; i < tickets->getSize(); i++) {
			tickets->goToPos(i);
			if (tickets->getElement().getCode() == code)
				tickets->remove();
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
		if (services->getSize() == 0) {
			services->append(service);
		}
		else {
			for (int i = 0; i < services->getSize(); i++) {
				services->goToPos(i);
				if ((services->getElement()).getDescription() == description) {
					services->append(service);
				}
			}
		}
	}

	/*
	* Elimina un servicio dentro del sistema
	* @param description Hilera con la descripción del servicio a eliminar
	*/
	void deleteService(string description) {
		for (int i = 0; i < services->getSize(); i++) {
			services->goToPos(i);
			if (services->getElement().getDescription() == description) {
				services->remove();
				tickets->clear();
			}
		}
	}

	/*
	* Genera un entero según el tipo de cliente y el servicio que el cliente posee
	* @param userPriority Entero indicando la prioridad del tipo de cliente
	* @param servicePriority Entero indicando la prioridad del servicio
	* @ret Entero con el indicando la prioridad de un cliente según su tipo y servicio
	*/
	int formula (int userPriority, int servicePriority) {
		return userPriority * 10 + servicePriority;
	}

	//Solicitud de un tiquete

	//Ventanilla tiene a tiquete

	// Administracion del sistema

	// Consulta de estadisticas
};

