/* Clase creada por Kevin Jimenez Escalante y Fabian Solis Izaguirre
* Esta clase es la implementacion de las areas
*/

#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "LinkedPriorityQueue.h"
#include "Ticket.h"
#include "Counter.h"
#include "LinkedList.h"

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;
using std::to_string;

template <typename E>
class Area
{
private:
	string description;
	string code;
	int numCounter;
	LinkedPriorityQueue<Ticket>* tickets;
	LinkedList<Counter> counters;

public:
	Area() {
	}

	Area(string descripcion, string code, int numCounter) {
		this->code = code;
		this->description = description;
		this->numCounter = numCounter;
		tickets = new LinkedPriorityQueue<Ticket>(110);
		initializeCounters();
	}

	~Area() {
	}

	void setDescription(string description) {
		this->description = description;
	}

	string getDescription() {
		return description;
	}

	void setCode(string code) {
		this->code = code;
	}

	string getCode() {
		return code;
	}

	void setNumCounter(int numCounter) {
		this->numCounter = numCounter;
		initializeCounters(); // Regenera la lista de ventanillas cada vez que cambia el número de ventanillas
	}


	string getNumCounter() {
		return numCounter;
	}

	void addTicket(Ticket ticket) {// Inserta el tiquete en la cola de prioridad del área
		tickets->insert(ticket, ticket.getFinalPriority());
	}
	Ticket attendNextTicket() {
		if (tickets->getSize() != 0) {
			return tickets->removeMin(); // Atiende el siguiente tiquete en orden de prioridad
		}
		throw std::runtime_error("No hay tiquetes en espera.");
	}

	bool distributeTicket() {
		if (tickets->getSize() == 0) {
			cout << "No hay tiquetes en espera." << endl;
			return false;
		}

		Ticket nextTicket = tickets->removeMin(); // Extrae el tiquete con mayor prioridad

		for (int i = 0; i < counters.getSize(); i++) {
			counters.goToPos(i);
			if (counters.getElement().assignTicket(nextTicket)) {
				cout << "Tiquete " << nextTicket.getCode() << " asignado a " << counters.getElement().getName() << endl;
				return true;
			}
		}

		cout << "Todas las ventanillas están ocupadas." << endl;
		return false;
	}

	void initializeCounters() { // inicializa las ventanillas segun el codigo del area
		counters.clear();
		for (int i = 1; i <= numCounter; i++) {
			string counterName = code + to_string(i);
			counters.append(Counter(counterName));
		}
	}

};