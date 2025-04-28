/* Clase creada por Javier Lee Liang
* Esta clase es una abstracción de cómo un servicio opera dentro del sistema de atención al cliente
*/
#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Service {
public:
	string description;
	string area;
	int priority;

	Service(string description, string area, int priority) {
		this->description = description;
		this->area = area;
		this->priority = priority;
	}

	~Service() {

	}

	void operator=(const Service& other) {
		description = other.description;
		area = other.area;
		priority = other.priority;
	}

	bool operator==(const Service& other) {
		return priority == other.priority;
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

ostream& operator<<(ostream& os, const Service& service) {
	return os << "(" << service.description << ", " << service.area << ", " << service.priority << ")";
}

