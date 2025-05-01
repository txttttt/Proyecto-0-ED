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

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class Area
{
private:
	string description;
	string code;
	int numCounter;
	List<Ticket>* tiquetes;

public:
	Area() {
	}

	Area(string descripcion, string codigo, int numVentanillas) {
		this->codigo = codigo;
		this->description = description;
		this->numVentanillas = numVentanillas;
		tiquetes = new LinkedPriorityQueue<Ticket>();
	}

	~Area() {
	}

	void setDescription(string description) {
		this->description = description;
	}

	string getDescription() {
		return description;
	}

	void setCode(String code) {
		this->code = code;
	}

	string getCode() {
		return code;
	}

	void setNumCounter(String numCounter) {
		this->numCounter = numCounter;
	}

	string getNumCounter() {
		return numCounter;
	}
};
