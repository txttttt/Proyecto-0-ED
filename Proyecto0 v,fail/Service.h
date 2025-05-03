/* Clase creada por Javier Lee Liang y Fabian Solis Izaguirre
 *Esta clase es una abstracción de cómo un servicio opera dentro del sistema de atención al cliente
 */
#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Service {
private:
	string description;
	string area;
	int priority;
	int ticketCount;

public:
	Service() {
		description = "";
		area = "";
		priority = 0;
		ticketCount = 0;
	}

	Service(string description, string area, int priority) {
		this->description = description;
		this->area = area;
		this->priority = priority;
		ticketCount = 0;
	}

	Service(const Service& other) {
		description = other.description;
		area = other.area;
		priority = other.priority;
		ticketCount = other.ticketCount;
	}

	~Service() {
	}

	void setDescription(string description) {
		this->description = description;
	}

	void setArea(string area) {
		this->area = area;
	}

	void setPriority(int priority) {
		if (priority >= 0) {
			this->priority = priority;
		}
		else {
			cout << "Error: La prioridad no puede ser negativa." << endl;
		}
	}
	
	void setTicketCount(int ticketCount) {
		this->ticketCount = ticketCount;
	}

	string getDescription() {
		return description;
	}

	string getArea() {
		return area;
	}

	int getPriority() {
		return priority;
	}

	int getTicketCount() {
		return ticketCount;
	}

	void incrementTicketCount() {
		ticketCount++;
	}

	void operator=(const Service& other) {
		description = other.description;
		area = other.area;
		priority = other.priority;
	}

	bool operator==(const Service& other) { //para poder comparar servicios por cualquiera de sus elementos.
		return (description == other.description) &&
			(area == other.area) &&
			(priority == other.priority);
	}

	bool operator!=(const Service& other) {
		return priority != other.priority;
	}

	bool operator<(const Service& other) {
		return priority < other.priority;
	}

	bool operator<=(const Service& other) {
		return priority <= other.priority;
	}

	bool operator>(const Service& other) {
		return priority > other.priority;
	}

	bool operator>=(const Service& other) {
		return priority >= other.priority;
	}
};

ostream& operator<<(ostream& os, Service& service) {
	return os << "(" << service.getDescription() << ", " << service.getArea() << ", " << service.getPriority() << ")";
}