/*Clase creada por Fabian Solis Izaguirre y Kevin Jimenez Escalante
* Implementacion de la clase ticket
*/
#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "LinkedPriorityQueue.h"

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;
using std::ostream;

class Ticket {
private:
	string code;
	float hour;
	int finalPriority;
public:
	Ticket() {}
	Ticket(string code, float hour, int finalPriority) {
		this->code = code;
		this->hour = hour;
		this->finalPriority = finalPriority;
	}
	Ticket(const Ticket& other) { // constructor para listas o colas
		code = other.code;
		hour = other.hour;
		finalPriority = other.finalPriority;
	}

	void setCode(string code) {
		this->code = code;
	}

	string getCode() {
		return code;
	}

	void setHour(float hour) {
		this->hour = hour;
	}

	float getHour() {
		return hour;
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
	return os << "(" << ticket.getCode() << ", " << ticket.getHour() << ", " << ticket.getFinalPriority() << ")";
}
