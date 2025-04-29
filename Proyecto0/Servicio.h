/* Clase creada por Javier Lee Liang
* Esta clase es una abstracción de cómo un servicio opera dentro del sistema de atención al cliente
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

public:

	Service() {
	}

	Service(string description, string area, int priority) {
		this->description = description;
		this->area = area;
		this->priority = priority;
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
		this->priority = priority;
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

ostream& operator<<(ostream& os, Service& service) {
	return os << "(" << service.getDescription() << ", " << service.getArea() << ", " << service.getPriority() << ")";
}

