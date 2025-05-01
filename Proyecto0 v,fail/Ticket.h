/*Clase creada por Fabian Solis Izaguirre y Kevin Jimenez Escalante
* Implementacion de la clase ticket
*/
#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include "LinkedPriorityQueue.h"

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;
using std::ostream;
// Se hace uso de la libreria time, en AdmSystem se provee mas informacion
using std::time;
using std::time_t;

class Ticket {
private:
	// Creation el el instante de tiempo en el que se instancio un nuevo ticket
	time_t creation;
	string code;
	int finalPriority;
public:
	Ticket() {}
	Ticket(string code, int finalPriority) {
		time_t now;
		time(&now);
		this->code = code;
		this->creation = now;
		this->finalPriority = finalPriority;
	}
	Ticket(const Ticket& other) { // constructor para listas o colas
		code = other.code;
		creation = other.creation;
		finalPriority = other.finalPriority;
	}

	void setCode(string code) {
		this->code = code;
	}

	string getCode() {
		return code;
	}

	void setCreation(time_t creation) {
		this->creation = creation;
	}

	time_t getCreation() {
		return creation;
	}

	void setFinalPriority(int fp) {
		this->finalPriority = fp;
	}

	int getFinalPriority() {
		return finalPriority;
	}

	bool operator==(const Ticket& other) {
		return code == other.code;
	}
	bool operator<(const Ticket& other) const {
		return finalPriority < other.finalPriority;
	}

};

ostream& operator<<(ostream& os, Ticket& ticket) {
	return os << "(" << ticket.getCode() << ", " << ticket.getCreation() << ", " << ticket.getFinalPriority() << ")";
}
