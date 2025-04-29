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

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;


class AdminSystem
{
private:
	ArrayList<KVPair<string, int>>* types;
	ArrayList<Ticket>* tickets;
	ArrayList<Service>* services;

public:
	void addType(string description, int priority) {
		KVPair<string, int>* pair = new KVPair<string, int>(description, priority);
		if (!types->contains(*pair)) {
			types->append(*pair);
		}
	}

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

	void addTicket(string code, float hour, int finalPriority) {
		Ticket* ticket = new Ticket(code, hour, finalPriority);
		if (!tickets->contains(*ticket))
			tickets->append(*ticket);
	}

	void deleteTicket(string code) {
		for (int i = 0; i < tickets->getSize(); i++) {
			tickets->goToPos(i);
			if (tickets->getElement().getCode() == code)
				tickets->remove();
		}
	}

	void addService(string description, string area, int priority) {
		for (int i = 0; i < services->getSize(); i++) {
			services->goToPos(i);
			if (services->getElement().getDescription() == description) {
				Service* service = new Service(description, area, priority);
				services->append(*service);
			}
		}
	}

	void deleteService(string description) {
		for (int i = 0; i < services->getSize(); i++) {
			services->goToPos(i);
			if (services->getElement().getDescription() == description) {
				services->remove();
				tickets->clear();
			}
		}
	}

	//Solicitud de un tiquete

	//Ventanilla tiene a tiquete

	// Administracion del sistema

	// Consulta de estadisticas
};

